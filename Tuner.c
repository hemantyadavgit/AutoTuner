#include <p24fj32GA004.h>
#define FCY  16000000
#include <libpic30.h>
#include "config.h"
#include <string.h> 
#include <stdio.h>
#include <math.h>

#include "ADC.h"
#include "graphic.h"
#include "music.h"
#include "test.h"
#include "animation.h"


#define TEST 0	



#define BUFSIZE 1500
#define PERIOD	15		// Sample Period in micro seconds
#define NOTUSED 10
#define SAMPLECOND 900
#define CMEAN_THRESHOLD 0.08
#define FREQ_MIN 100
#define FREQ_MAX 1200
#define COUNTS 1




unsigned short int adbuf[BUFSIZE] = {0};
unsigned char dataget = 0;
unsigned char presample = 1;
unsigned char hold = 0;
unsigned short int adbufpre;



void T2_Init();

void __attribute__((__interrupt__))_T2Interrupt()
{
	IFS0bits.T2IF = 0;
	AD1CON1bits.SAMP = 1;

}


void __attribute__((__interrupt__))_ADC1Interrupt()
{
 	static	unsigned short int index = 0;

	IFS0bits.AD1IF = 0;

	if(presample)
	{
		adbufpre =  ADC1BUF0;

	}

	else
	{
		adbuf[index] = ADC1BUF0;
		index++;	
		if( index == BUFSIZE ) 				// Data Has Been Collected
		{
			dataget = 1;
			index = 0;
			T2CONbits.TON = 0;	
		}
	}


}


void T2_Init()
{
	T2CONbits.TCKPS = 1;			// 1:8 Prescaler, 0.5us per Tick
	T2CONbits.T32 = 0;				// Timer2 as A 16bit Timer
	T2CONbits.TCS = 0;				// Internal Clock

	TMR2 = 0;
	PR2 = PERIOD*2 - 1;			

	T2CONbits.TON = 0;				// Turn Off Timer2
	
}




void setup()
{
		AD1PCFG = 0xFFFF; 		//turn off ADC

		TRISA = 0;
		TRISB = 0;
		TRISC = 0;
		
		PORTA = 0;
		PORTB = 0;
		PORTC = 0;
		

		GLCD_Init();
		
		T2_Init();

		ADC_Init();

	/*   Adjust Interrupt Priority  */
	


	/*   Adjust Interrupt Priority  */
			
	
		
	/*   Enable Interrupts  */
		IFS0bits.AD1IF = 0;
		IEC0bits.AD1IE = 1;	
		IFS0bits.T2IF = 0;
		IEC0bits.T2IE = 1;
	/*   Enable Interrupts  */

}
 

void main()
{
	unsigned char counts = 0;
	unsigned int most_count = 0; 
	unsigned long int totaldiff = 0;
	unsigned long int totaldiffmin = 0;
	unsigned short int delay;
	unsigned short int delaymin;
	unsigned short int delaytime ;
	unsigned short int i,j,most_index;
	unsigned short int period = 0;
	unsigned long int totaldiff_mean = 0;
	unsigned long long totaldiff_sum = 0;

	float most;
	float cmean,cmean_min;
	float freq_record[COUNTS] = {0};


	unsigned char out[16];
	float freq;
	float freq_total = 0;
	unsigned char findex = 0;	

	setup();

	if(TEST)
	{
		test();
	}

	GLCD_Out_Inc("Welcome!");


	__delay_ms(1200);
	

	while(1)
	{


		T2CONbits.TON = 1;
		while(adbufpre <= SAMPLECOND);								// Wait for the Signal to Stablize
		presample = 0;
		adbufpre = 0;
		GLCD_Clear();

		GLCD_Out(3,1,"Analyzing!");
		__delay_ms(20);

		for(counts = 0 ; counts < COUNTS ; counts++)
		{
			while(!dataget);		
	
			delaytime = 0;
			cmean_min = 1.0;
			cmean = 1.0;

			for( i = 0 ; i < BUFSIZE/2 ; i++ )
			{
				for( j = i + NOTUSED ; j < i + BUFSIZE/2 ; j ++ ) 
				{
					totaldiff+= abs((long )adbuf[j-i] - (long )adbuf[j]);
	
				}
	
	
				if( i > 0 ) 
				{
					totaldiff_sum += totaldiff;
					totaldiff_mean = totaldiff_sum / i ;
					cmean =  (totaldiff*1.0/totaldiff_mean)*(totaldiff*1.0/totaldiff_mean);
				}
	
			
			
				if( cmean < CMEAN_THRESHOLD && cmean > cmean_min &&  i != NOTUSED ) 
				{
					delaytime = PERIOD*(i - 1);
					totaldiff_sum = 0;
					totaldiff = 0 ; 
					goto done;
				}
	
				if( cmean < cmean_min ) 
				{
					cmean_min = cmean;
	
				}
				totaldiff = 0;
			}	
	
		
	
			done:
			if( i == 500 || delaytime == 0 || delaytime <= NOTUSED || delaytime == PERIOD )	//error correction
			{
				error:
				GLCD_Clear();
				GLCD_Out(2,2,"Try again.");
				goto next;
			}
			
			else
			{
				GLCD_Out(2,1,"               ");
				freq = 1000000.0 / Ave(delaytime,delaytime + 1);
				if(freq < FREQ_MIN || freq > FREQ_MAX )
				{
					GLCD_Out(2,2,"Out of range!");
					goto next;
				}

			}
	
			//freq_record[counts] = freq;	
	

		}

		GLCD_ClearRow(0);
		GLCD_ClearRow(1);
		GLCD_ClearRow(2);
		GLCD_ClearRow(3);

		sprintf(out,"Freq: %.2f",freq);
		GLCD_Out(0,1,out);

		GLCD_Out(1,1,getNote(getIndexOfNote(freq).car));

		drawArrows(3,1);
		fillArrow(3,1,getError(freq,getIndexOfNote(freq).cdr));
	

			dataget = 0;
			T2CONbits.TON = 1;

		__delay_ms(1500);
		next:
		presample = 1;
		


			
	}


}

