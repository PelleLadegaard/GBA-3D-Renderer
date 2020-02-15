#pragma once

#include "../GBA/gba_types.h"

class Poly;
class Camera;
class vec2;
class vec3;

////////////////////////
//Variables
////////////////////////
extern u16* CurrentBuffer;

////////////////////////
//Functions
////////////////////////

// Drawing
	// Draws a pixel on the buffer you're currently drawing to
INLINE void drawPixel(int x, int y, u16 clrid){
	CurrentBuffer[(x*160+y)] = clrid;
}

// Misc
	// Extends 8-bit data over a 32-bit variable 4 times
u32 quad8(u8 x);
u32 quad16(u16 x);

// Rendering buffers
	// Swaps the front and back buffer
void swapBuffers();
	// Clears the buffer you're currently drawing to
void clearBuffer();



// Polygon rendering
	// Raw (risky)
void IWRAM_CODE drawTriangle(const Poly &tri);
	// Clipped (safe)
void IWRAM_CODE drawTriangleClipped(const Poly &tri);



// Line rendering
void drawLineLow(int x0,int y0, int x1,int y1, u16 col);
void drawLineHigh(int x0,int y0, int x1,int y1, u16 col);
void drawLine(int x0,int y0, int x1,int y1, u16 col);



// Projecting
vec2 IWRAM_CODE projectVertex(const vec3& vert, const Camera& cam, const vec3& tpos, int rotation);