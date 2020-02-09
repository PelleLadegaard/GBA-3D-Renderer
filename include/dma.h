#pragma once

#include "gba_types.h"

#define BREST		((u32)0x85000000)

#define DMA_SRC 	*((u32*)0x40000B0)
#define DMA_DST 	*((u32*)0x40000B4)
#define DMA_CTRL	*((u32*)0x40000B8)

#define DMA_START			0x8000
#define DMA_SRC_REMAIN		0x1000
#define DMA_WORD			0x400

void dmaSet32(volatile u32 *src, volatile u32 *dest, volatile int size){
	DMA_SRC = (u32)src;
	DMA_DST = (u32)dest;
	
	//DMA_CTRL = DMA_START | DMA_SRC_REMAIN | (u16)size;
	DMA_CTRL = (BREST | (u32)size);
}

// Not actually DMA, but a fast memory fill equivalent that works for 16 bit data
void IWRAM_CODE dmaFill16(void* dest, u32 WordCount, u16 val_fill) {
	u16* destVar = (u16*)dest;
	for (u32 i=0; i < WordCount; i++){
		*destVar++ = val_fill;
	}
}