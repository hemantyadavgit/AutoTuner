#include "GLCD_24.h"

//Just some symbols.
#define ARROW_RIGHT 0
#define ARROW_RIGHT_FILLED 1
#define ARROW_LEFT 2
#define ARROW_LEFT_FILLED 3
#define FILL 4

void drawArrows(unsigned char x,unsigned char y)
{	
	unsigned char i;

	for(i = 0; i < 6 ; i++)
	{
		GLCD_Sym(x,y+i,ARROW_RIGHT);
	}

	GLCD_Char(x,y+6,' ');

	for(i = 0; i < 6 ; i++)
	{
		GLCD_Sym(x,y+ 7 + i,ARROW_LEFT);
	}

}

void fillArrow(unsigned char x, unsigned char y, int cents)
{
	unsigned char i;
	if(cents <5 && cents >-5)
	{
		GLCD_Sym(x,y + 6,FILL);
	}

	else 	if(cents >= 5 && cents <= 30)
	{
		GLCD_Sym(x, y + 6 + (unsigned char) cents/5,ARROW_LEFT_FILLED);
	}

	else 	if(cents > 30 && cents < 50)
	{
		for(i = 7; i < 13 ; i++)
		{
			GLCD_Sym(x,y + i,ARROW_LEFT_FILLED);
		}
	}

	else 	if(cents <= -5 && cents >= -30)
	{

		GLCD_Sym(x, y + ((unsigned char) (30+cents))/5,ARROW_RIGHT_FILLED);


	}

	else if(cents < -30 && cents > -50)
	{
		for(i = 0; i < 6 ; i++)
		{
			GLCD_Sym(x,y + i,ARROW_RIGHT_FILLED);
		}
	}

	else
	{
		GLCD_Out(1,1,"Freq is out of range.");

	}
	

}