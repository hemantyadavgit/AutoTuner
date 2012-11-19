#include <math.h>


#define TOLERANCE 0.02
#define ZERO 0.001
unsigned char closeEnough(float a,float b,float t)
{
	if(b == 0) return abs(a) < ZERO;
	if(a == 0) return abs(b) < ZERO;
	
	return fabsf((a-b)/b) <= t;		//Might not work for small number!
}


float findMost(float *data,unsigned int size)
{	//require sorted array

	unsigned int index = 0;
	float most = *data,most_count = 1,most_poss_count = 1;
	float most_poss = *data;
	
	if(size == 1) return *data;
	
	for(index = 1; index<size ; index++)
	{
		if(closeEnough(most_poss,*(data + index),TOLERANCE)) most_poss_count++;		// there ares more
		else
		{	
			most_poss = *(data + index);
			most_poss_count = 1;
		}

		if(most_poss_count > most_count)
		{
			most = most_poss;
			most_count =  most_poss_count;
		}

	}

	return most;

}


void insertSort(float * data,unsigned int size)
{
	unsigned int i,j;
	float e;
	
	for( i = 1; i < size ; i++)
	{
		e = *(data + i);
		j = i;
		while((j>0) && *(data + j - 1) > e )
		{
			*(data + j ) = *(data + j - 1);
			j--;
		}
		*(data + j ) = e;
	}
}


float Ave(float d1,float d2)
{
	return ((d1+d2)/2.0);
}


#define LOG10_2 0.30103 // log10(2)

// From  base-10 to base-2
float log2f(float d)
{
	return (log10f(d)/ LOG10_2);
}

int roundInt(float d)
{
	float fraction;
	fraction = (int)(d*10) % 10;

	if(fraction > 4) return ceilf(d);
	else return  floorf(d);

}