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
#include "DMA.h"


/*! This array hold the initial picture that is shown in the LCD. Note that extern should be avoided*/
extern const uint8_t ITESO[504];
extern uint8_t img_1[504];
extern uint8_t img_2[504];
extern uint8_t img_3[504];
extern uint8_t img_4[504];
extern uint8_t img_5[504];

int main(void)
{

	DMAMUX_SetPeriodicTrigger(DMAMUX0, kDMAChannel0, DMA_SOURCE_AE);
	EDMA_InitConfig(DMA0);
	DMA_SetHandle(kDMAChannel0);

	SPI_config();

	LCD_nokia_init(); /*! Configuration function for the LCD */

	for(;;) {

		LCD_nokia_clear();/*! It clears the information printed in the LCD*/

		LCD_nokia_bitmap(ITESO); /*! It prints an array that hold an image, in this case is the initial picture*/
		delay(65000);
		LCD_nokia_clear();

		LCD_nokia_bitmap(img_1);
		delay(65000);
		LCD_nokia_clear();

		LCD_nokia_bitmap(img_2);
		delay(65000);
		LCD_nokia_clear();

		LCD_nokia_bitmap(img_3);
		delay(65000);
		LCD_nokia_clear();

		LCD_nokia_bitmap(img_4);
		delay(65000);
		LCD_nokia_clear();

		LCD_nokia_bitmap(img_5);
		delay(65000);
		LCD_nokia_clear();

		delay(65000);
	}
	
	return 0;
}

