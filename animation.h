

// ------------------------------------------------------  
// GLCD Picture name: sine.bmp            
// GLCD Model: KS0108 128x64            
// ------------------------------------------------------  

// ------------------------------------------------------  
// GLCD Picture name: sine.bmp            
// GLCD Model: KS0108 128x64            
// ------------------------------------------------------  

const unsigned char QUESTION[512] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  32,  32,  32,  32,  32,  64, 192,   0,   0,   0,   0,   0, 128,  64,  32,  32,  32,  32,  32,  64, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  32,  32,  32,  32,  32,  64, 192,   0,   0,   0,   0,   0, 128,  64,  32,  32,  32,  32,  32,  64, 192,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  32,  32,  32,  32,  32,  64, 192,   0,   0,   0,   0,   0, 128,  64,  32,  32,  32,  32,  32,  64, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  15,  12,  12,   0,   0, 128, 192,  96,  48,  31,  15,   0,   0,   0,  15,  12,  12,   0,   0, 128, 192,  96,  48,  31,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  15,  12,  12,   0,   0, 128, 192,  96,  48,  31,  15,   0,   0,   0,  15,  12,  12,   0,   0, 128, 192,  96,  48,  31,  15,   0,   0,   0,   0,   0,   0,  15,  12,  12,   0,   0, 128, 192,  96,  48,  31,  15,   0,   0,   0,  15,  12,  12,   0,   0, 128, 192,  96,  48,  31,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 231, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 231, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 231, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 231, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 231, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 231, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
};





void question(unsigned char *image)
{
	static unsigned int displace = 0;
    unsigned i, j;

    for(i=0;i<4;i++)
        {
	        GLCD_Command(0xb0 | i);    // select page 0~7
			GLCD_Command(0x10);   
			GLCD_Command(0x00);        
	
	        for(j = displace ;j < 128 ;j++)
	       	{

				GLCD_Data(*image);
				image++;
	        }
	        for(j = 0 ;j < displace ;j++)
	       {

				GLCD_Data(*image);
				image++;
	        }
        }

	displace++;
	displace=displace&128;

}