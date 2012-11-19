
/*
 *		Write a command to the lcd. Takes in a byte.
 */
void GLCD_Data(unsigned char out);


/*
 *		Write a command to the lcd.
 */
void GLCD_Command(unsigned char out);


/*
 *		Write a byte to SPI slave.
 */
void SPI_Init();


/*
 *		Write a byte to SPI slave.
 */
void SPI_Out(unsigned char out);


/*
 *		Draw a given bitmap.
 */
void GLCD_Draw_Bitmap(unsigned char *DisplayData);


/*
 *		Clear the lcd(the lcd would blink).
 */
void GLCD_Clear(void);


/*
 *		Print out a string at specified x,y position and move the cursor accordingly.
 */
void GLCD_Out(unsigned char x, unsigned char y,unsigned char * out);


/*
 *		Print out a string at current cursor position and move the cursor accordingly.
 */
void GLCD_Out_Inc(unsigned char * out);


/*
 *		Print out a character at specified x,y position and move the cursor accordingly.
 */
void GLCD_Char(unsigned char x, unsigned char y,unsigned char out);


/*
 *		Print out a character current cursor position and move the cursor accordingly.
 */
void GLCD_Char_Inc(unsigned char out);


/*
 *		Print out a symbol at specified x,y position and move the cursor accordingly.
 */
void GLCD_Sym(unsigned char x, unsigned char y,unsigned char out);


/*
 *		Print out a symbol at current cursor position and move the cursor accordingly.
 */
void GLCD_Sym_Inc(unsigned char out);

/*
 *		Set the position of the cursor.
 */
void GLCD_SETCURSOR(unsigned char x, unsigned char y);


/*
 *		Clear a specific row.
 */
void GLCD_ClearRow(unsigned char x);

/*
 *		Initialize IO pins.
 */
void IO_Init();

/*
 *		Initialize serial interface.
 */
void SPI_Init();