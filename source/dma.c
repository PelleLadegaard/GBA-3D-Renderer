/*#include "dma.h"

void *__toncset(void *dst, u32 fill, uint size)
{
	if(dst==0 || size==0)
		return dst;

	uint left= (u32)dst&3;
	u32 *dst32= (u32*)(dst-left);
	u32 count, mask;

	// Unaligned head.
	if(left != 0)
	{
		// Adjust for very small stint.
		if(left+size<4)
		{
			mask= BIT_MASK(size*8)<<(left*8);	
			*dst32= (*dst32 &~ mask) | (fill & mask);
			return dst;
		}

		mask= BIT_MASK(left*8);
		*dst32= (*dst32 & mask) | (fill&~mask);
		dst32++;
		size -= 4-left;
	}

	// Main stint.
	count= size/4;
	uint tmp= count&3;
	count /= 4;

	switch(tmp) {
		do {	*dst32++ = fill;
	case 3:		*dst32++ = fill;
	case 2:		*dst32++ = fill;
	case 1:		*dst32++ = fill;
	case 0:		; }	while(count--);
	}

	// Tail
	size &= 3;
	if(size)
	{
		mask= BIT_MASK(size*8);
		*dst32= (*dst32 &~ mask) | (fill & mask);
	}

	return dst;
}*/