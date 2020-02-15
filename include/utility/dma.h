#pragma once

#include "gba_types.h"

#define BREST		((u32)0x85000000)

#define DMA_SRC 	*((u32*)0x40000B0)
#define DMA_DST 	*((u32*)0x40000B4)
#define DMA_CTRL	*((u32*)0x40000B8)

#define DMA_START			0x8000
#define DMA_SRC_REMAIN		0x1000
#define DMA_WORD			0x400

void dmaSet32(volatile u32 *src, volatile u32 *dest, volatile int size);

// Not actually DMA, but a fast memory fill equivalent that works for 16 bit data
void IWRAM_CODE dmaFill16(void* dest, u32 WordCount, u16 val_fill);