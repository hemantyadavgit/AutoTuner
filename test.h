
void test()
{
	unsigned char out[16] = {0};
	

	/*
	sprintf(out,"%d",closeEnough(freq,440.00,ERROR_40));
	GLCD_Out(0,0,out); 

	sprintf(out,"%d",closeEnough(freq,466.16,ERROR_40));
	GLCD_Out(1,0,out); */


	/*
	// 19cents higher than A#
	float freq = 471.30;
	sprintf(out,"Freq: %.2f",freq);
	GLCD_Out(0,1,out);
	GLCD_Out(1,1,getNote(getIndexOfNote(freq).car));
	drawArrows(3,1);
	fillArrow(3,1,getError(freq,getIndexOfNote(freq).cdr));
	*/


	float freqArray[] = {330,328.35,446.3,427.2,878.8,217.6,0};

	while(1)
	{
		multiFreqTest(freqArray);
	}


}

void freqTest(float freq)
{
	unsigned char out[16] = {0};
	GLCD_Clear();


	sprintf(out,"Freq: %.2f",freq);
	GLCD_Out(0,1,out);
	GLCD_Out(1,1,getNote(getIndexOfNote(freq).car));

	drawArrows(3,1);
	fillArrow(3,1,getError(freq,getIndexOfNote(freq).cdr));
	

}

void multiFreqTest(float * fptr)
{
	while(*fptr)
	{
		freqTest(*fptr);
		fptr++;
		__delay_ms(3000);
	}

}