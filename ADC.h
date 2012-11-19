
void ADC_Init()
{
	TRISAbits.TRISA0 = 1;

	AD1PCFG = 0xFFFE; 		// AN0 as Analog Input

	AD1CON1bits.FORM = 0;			// ADC Format >> Integer
	AD1CON1bits.SSRC = 7;			// Internal Counter Ends Sampling and Start Conversion
	AD1CON1bits.ASAM = 0;			// Manual Sampling 

	AD1CON2bits.VCFG = 0;			// AVDD & AVSS as Reference
	AD1CON2bits.CSCNA = 0;			// Do not Scan Inputs
	AD1CON2bits.SMPI = 0;			// Interrupt Whenever Conversion Complets
	AD1CON2bits.BUFM = 0;			// Buffer Configured as One Word
	AD1CON2bits.ALTS = 0;			// Always Use Mux A

	AD1CON3bits.SAMC = 8;			// Sample Time = 8TAD = 1us
	AD1CON3bits.ADCS = 1;			// TAD = 2TCYC = 125 ns > 75ns

	AD1CHSbits.CH0NA = 0;			// VR- as CH0 Negative Input
	AD1CHSbits.CH0SA = 0;			// AN0 as CH0 Positive Input

	AD1CON1bits.ADON = 1;			// Enable ADC

		
}