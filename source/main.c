/**
	\file 
	\brief 
		This is a starter file to use the Nokia 5510 LCD. 
		The LCD is connected as follows:
		RST-PDT5
		CE-PTD0
		DC-PTD4
		DIN-PTD2
		CLK-PTD1
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	19/09/2019
	\todo
	    The SPI device driver needs to be completed.
 */

 

#include "LCD_nokia.h"
#include "LCD_nokia_images.h"
#include "stdint.h"
#include "SPI.h"
#include "Delay.h"


/*! This array hold the initial picture that is shown in the LCD. Note that extern should be avoided*/



uint8_t read_byte = 0x03;

int main(void)
{

	SPI_config_LCD();
	SPI_config_MEM();
	LCD_nokia_init(); /*! Configuration function for the LCD */

	for(;;) {

		LCD_nokia_clear();/*! It clears the information printed in the LCD*/
		LCD_readImg();
		delay(65000);
	}
	
	return 0;
}

