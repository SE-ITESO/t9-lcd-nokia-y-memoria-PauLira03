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
#include "PIT.h"
#include "NVIC.h"


uint8_t delay(bool is_on);

/*! This array hold the initial picture that is shown in the LCD. Note that extern should be avoided*/



uint32_t five_ms=50000;
uint8_t counter=0;

int main(void)
{
	pit_config_t pitConfig;
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_4);
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT_BASEADDR, &pitConfig);
	PIT_set_timer_period(PIT_CHANNEL0, five_ms);
	PIT_StartTimer(PIT_BASEADDR, PIT_CHANNEL0);

	PIT_callback_init(delay);


	SPI_config_LCD();
	SPI_config_MEM();
	LCD_nokia_init(); /*! Configuration function for the LCD */

	for(;;) {
		if(true == counter){
			LCD_nokia_clear();/*! It clears the information printed in the LCD*/
			LCD_readImg();
			counter = false;
		}
	}
	
	return 0;
}

uint8_t delay(bool is_on){
	counter = true;
	return 0;
}


