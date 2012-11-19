#include<math.h>
#include"cal.h"

typedef struct 
{
	int car; 
	float cdr;
}
pair;



#define ERROR_40 0.023374

// factor for 5 cents
#define FACTOR_5 1.002892

const float SMALL[12] = {130.81,138.59,146.83,155.56,164.81,174.64,185.00,196.00,207.65,220.00,233.08,246.94};
const float ONELINE[12] = {261.63,277.18,293.66,311.13,329.63,349.23,369.99,392.00,415.30,440.00,466.16,493.88};
const float TWOLINE[12] = {523.25,554.37,587.33,622.25,659.26,698.46,739.99,783.99,830.61,880.00,932.33,987.77};

unsigned char* getNote(unsigned char index)
{
	switch(index)
	{
		case 0  : return "C ";
		case 1  : return "C#";
		case 2  : return "D ";
		case 3  : return "D#";
		case 4  : return "E ";
		case 5  : return "F ";
		case 6  : return "F#";
		case 7  : return "G ";
		case 8  : return "G#";
		case 9  : return "A ";
		case 10 : return "A#";
		case 11 : return "B ";
		case 12 : return "  ";
	}

}

pair getIndexOfNote(float freq)
{
	unsigned int i;
	pair p;

	for(i = 0 ; i < 12 ; i++)
	{
		if(closeEnough(freq,SMALL[i],ERROR_40))
		{
			p.car = i;
			p.cdr = SMALL[i];
			return p;
		}
		
	}

	for(i = 0 ; i < 12 ; i++)
	{
		if(closeEnough(freq,ONELINE[i],ERROR_40))
		{
			p.car = i;
			p.cdr = ONELINE[i];
			return p;
		}
		
	}


	for(i = 0 ; i < 12 ; i++)
	{
		if(closeEnough(freq,TWOLINE[i],ERROR_40))
		{
			p.car = i;
			p.cdr = TWOLINE[i];
			return p;
		}
		
	}

	p.car = 12;
	p.cdr = 10000;

	return p;
}

// Calculate how many cents the note is off the center freq.
char getError(float freq , float note)
{
	return roundInt(1200*log2f(freq/note));

}