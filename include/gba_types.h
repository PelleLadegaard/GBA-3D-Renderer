//
// Variable types
//
 
#pragma once
 
typedef unsigned char    u8;
typedef unsigned short   u16;
typedef unsigned long    u32;
 
typedef signed char      s8;
typedef signed short     s16;
typedef signed long      s32;
 
#define RGB(r,g,b)   ((u16)(r | (g<<5) | (b<<10)))

#define IWRAM_CODE __attribute__((section(".iwram"), long_call))
#define INLINE static inline