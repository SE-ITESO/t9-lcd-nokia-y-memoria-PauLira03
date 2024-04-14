/*
 * DMA.h
 *
 *  Created on: 9 abr. 2024
 *      Author: roman
 *      Description: Device driver to use functions to configure DMAMUX and EDMA registers
 */

#ifndef DMA_H_
#define DMA_H_

#include <stdint.h>
#include "fsl_edma.h"
#include "fsl_dmamux.h"

#define TCD_QUEUE_SIZE      1U
#define DMA_SOURCE_AE		(58u) // Source AE = Always Enabled

typedef enum _dma_channels
{
	kDMAChannel0 = 0U,
	kDMAChannel1 = 1U,
	kDMAChannel2 = 2U,
	kDMAChannel3 = 3U,
	kDMAChannel4 = 4U,
	kDMAChannel5 = 5U,
	kDMAChannel6 = 6U,
	kDMAChannel7 = 7U,
	kDMAChannel8 = 8U,
	kDMAChannel9 = 9U,
	kDMAChannel10 = 10U,
	kDMAChannel11 = 11U,
	kDMAChannel12 = 12U,
	kDMAChannel13 = 13U,
	kDMAChannel14 = 14U,
	kDMAChannel15 = 15U,
} dma_channel_t;

void EDMA_Callback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

void DMAMUX_SetPeriodicTrigger(DMAMUX_Type *base, dma_channel_t channel, uint16_t source);
void EDMA_InitConfig(DMA_Type *base);
void DMA_SetHandle(dma_channel_t channel);

void DMA_StartXfer();
void DMA_StopXfer();

#endif /* DMA_H_ */
