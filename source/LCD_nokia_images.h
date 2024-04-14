/*
 * LCD_nokia_images.h
 *
 *  Created on: 25/09/2018
 *      Author: jlpe
 */

#ifndef LCD_NOKIA_IMAGES_H_
#define LCD_NOKIA_IMAGES_H_

#include "stdint.h"
#define DATA_WIDTH			(2U)
#define SRC_OFFSET			(2U)
#define DEST_OFFSET			(0U)
#define MINOR_LOOP_BYTES	(2U)
#define MAJOR_LOOP_COUNTS	(20)

typedef enum _img_addr
{
	kLCD_IMG_BASE_ADDR_1	= 28672,
	kLCD_IMG_BASE_ADDR_2	= 32768,
	kLCD_IMG_BASE_ADDR_3    = 36864,
	kLCD_IMG_BASE_ADDR_4	= 40960,
	kLCD_IMG_BASE_ADDR_5    = 45056,
}_img_addr_t;


#endif /* LCD_NOKIA_IMAGES_H_ */
