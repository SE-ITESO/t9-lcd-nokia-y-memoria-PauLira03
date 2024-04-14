/*
 * DAC.h
 *
 *  Created on: 22 feb. 2024
 *      Author: Roman y Paulina
 *      Description: Device driver to configure the DAC used.
 */

#ifndef DAC_H_
#define DAC_H_

#include <stdint.h>
#include <stdbool.h>
#include "MK64F12.h"
#include "fsl_dac.h"

#define DAC_REG_ADDR	(0x400CC000)

void DAC_clk_gating(uint32_t val);
void DAC_config(dac_config_t *config);
void DAC_init(DAC_Type *base, const dac_config_t *config);
void DAC_enable(DAC_Type *base);


#endif /* DAC_H_ */
