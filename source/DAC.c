/*
 * DAC.c
 *
 *  Created on: 22 feb. 2024
 *      Author: Roman y Paulina
 *      Description: Device driver to configure the DAC used.
 */

#include "DAC.h"
#include <stdint.h>
#include <stdbool.h>


/* Sets the basic configuration of the DAC */
void DAC_config(dac_config_t *config)
{
	DAC_GetDefaultConfig(config);
}

/* DAC initialization with the selected configuration */
void DAC_init(DAC_Type *base, const dac_config_t *config)
{
	DAC_Init(base, config);
}


/* Function to enable the DAC */
void DAC_enable(DAC_Type *base)
{
	DAC_Enable(DAC0, true);
}

