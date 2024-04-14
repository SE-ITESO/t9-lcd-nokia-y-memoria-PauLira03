/*
 * DMA.c
 *
 *  Created on: 9 abr. 2024
 *      Author: roman
 *      Description: Device driver to use functions to configure DMAMUX and EDMA registers
 */


#include <stdint.h>
#include <stdbool.h>
#include "DMA.h"

static edma_handle_t g_EDMA_Handle;
static bool g_Transfer_Done;

/* EDMA callback when major loop is finished */
void EDMA_Callback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    if (transferDone)
    {
        g_Transfer_Done = true;
    }
}

/* Initializes DMA with periodic triggering */
void DMAMUX_SetPeriodicTrigger(DMAMUX_Type *base, dma_channel_t channel, uint16_t source)
{
	DMAMUX_Init(base);
	DMAMUX_SetSource(base, channel, source);
	DMAMUX_EnablePeriodTrigger(base, channel);
	DMAMUX_EnableChannel(base, channel);
}

/* Uses default configuration to set EDMA */
void EDMA_InitConfig(DMA_Type *base)
{
	edma_config_t userConfig;
    EDMA_GetDefaultConfig(&userConfig);
    EDMA_Init(base, &userConfig);
}

/* Function to set callback for DMA major loop */
void DMA_SetHandle(dma_channel_t channel)
{
    EDMA_CreateHandle(&g_EDMA_Handle, DMA0, channel);
    EDMA_SetCallback(&g_EDMA_Handle, EDMA_Callback, NULL);
    EDMA_ResetChannel(g_EDMA_Handle.base, g_EDMA_Handle.channel);
}

void DMA_StartXfer()
{
	EDMA_StartTransfer(&g_EDMA_Handle);
}

void DMA_StopXfer()
{
	EDMA_StopTransfer(&g_EDMA_Handle);
}
