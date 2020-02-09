#pragma once

#include <string.h>
#include <algorithm>
#include <cstdlib>
#include "formats.h"
#include "dma.h"

//#include "timer.h"

////////////////////////
//Variables
////////////////////////
u16* CurrentBuffer     BackBuffer;

////////////////////////
//Functions
////////////////////////

//Misc
	//Extends 8-bit data over a 32-bit variable 4 times
u32 quad8(u8 x)	{	return x*0x01010101;	}
u32 quad16(u16 x){   return x|(x<<16);    }

//Rendering buffers
	//Swaps the front and back buffer
void swapBuffers(){
	REG_DISPCNT ^= 0x10;
	
	if (CurrentBuffer == FrontBuffer){
		CurrentBuffer = BackBuffer;
	}
	else{
		CurrentBuffer = FrontBuffer;
	}
}

	//Clears the buffer you're currently drawing to
void clearBuffer(){
	volatile u32 fillvalue = 0;
	dmaSet32(&fillvalue,(u32*)CurrentBuffer,9600);
}

//Drawing
	//Draws a pixel on the buffer you're currently drawing to
INLINE void IWRAM_CODE drawPixel(int x, int y, u16 clrid){
	CurrentBuffer[(x*160+y)] = clrid;  // Division by 2 due to u8/u16 pointer mismatch!
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Coloured polygon
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
INLINE void drawLineVertical(int ystart,int yend,int x, u16 col){
	u16* dest = CurrentBuffer+(x*160+ystart);
	for (int i=yend-ystart; i >= 0 ; i--){
		*dest++ = col;
	}
}

INLINE void drawRightFlatTriangle(vec2 v0,vec2 v1,vec2 v2, u16 col){
	if (v1.y > v2.y){
		std::swap(v1,v2);
	}
	
	int difx = (v1.x-v0.x);
	
	int invslope1 = (v1.y - v0.y) / difx;
	int invslope2 = (v2.y - v0.y) / difx;
	int cury1 = v0.y;
	int cury2 = v0.y;
	
	for (int scanlineX = v0.x; scanlineX <= v1.x; scanlineX++){
		drawLineVertical(cury1>>16,cury2>>16,scanlineX, col);
		cury1 += invslope1;
		cury2 += invslope2;
	}
}

INLINE void drawLeftFlatTriangle(vec2 v0,vec2 v1,vec2 v2, u16 col){
	if (v0.y > v1.y){
		std::swap(v0,v1);
	}
	
	int difx = (v2.x - v0.x);
	
	int invslope1 = (v2.y - v0.y) / difx;
	int invslope2 = (v2.y - v1.y) / difx;
	int cury1 = v2.y;
	int cury2 = v2.y;
	
	for (int scanlineX = v2.x; scanlineX > v0.x; scanlineX--){
		drawLineVertical(cury1>>16,cury2>>16,scanlineX, col);
		cury1 -= invslope1;
		cury2 -= invslope2;
	}
}

void IWRAM_CODE drawTriangle(const Poly &tri){
	vec2 v0,v1,v2;
	v0 = tri.v0;
	v1 = tri.v1;
	v2 = tri.v2;
	
	if (!clockwise(v2,v1,v0)){return;}
	
	//Sort the vertex list from bottom to top
	if (v0.x == max(v0.x,v1.x)){
		std::swap(v0,v1);
	}
	if (v1.x == max(v1.x,v2.x)){
		std::swap(v1,v2);
	}
	if (v0.x == max(v0.x,v1.x)){
		std::swap(v0,v1);
	}
	
	
	
	//check for trivial case of bottom-flat triangle
	if (v1.x == v2.x){
		drawRightFlatTriangle(v0,v1,v2, tri.col);
	}
	//check for trivial case of top-flat triangle 
	else if (v0.x == v1.x){
		drawLeftFlatTriangle(v0,v1,v2, tri.col);
	} 
	else{
		//general case - split the triangle in a topflat and bottom-flat one
		int lerpmult = ((v1.x - v0.x)<<16) / (v2.x - v0.x);
		vec2 v3{v1.x, v0.y + lerpmult*((v2.y - v0.y)>>16)};
		drawRightFlatTriangle(v0,v1,v3, tri.col);
		drawLeftFlatTriangle(v1,v3,v2, tri.col);
	}
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Clipped coloured polygon
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
INLINE void drawLineVerticalClipped(int ystart,int yend,int x, u16 col){
	int begin = max(ystart,0);
	u16* dest = CurrentBuffer+(x*160+begin);
	for (int i=min(yend,SCREEN_HEIGHT-1)-begin; i >= 0 ; i--){
		*dest++ = col;
	}
}

INLINE void drawRightFlatTriangleClipped(vec2 v0,vec2 v1,vec2 v2, u16 col){
	if (v1.y > v2.y){
		std::swap(v1,v2);
	}
	
	int difx = (v1.x-v0.x);
	
	int invslope1 = (v1.y - v0.y) / difx;
	int invslope2 = (v2.y - v0.y) / difx;
	int cury1 = v0.y;
	int cury2 = v0.y;
	
	if (v0.x < 0){
		int diff = v0.x*-1;
		cury1 += invslope1*diff;
		cury2 += invslope2*diff;
	}
	
	int end = min(v1.x,SCREEN_WIDTH-1);
	for (int scanlineX = max(v0.x,0); scanlineX <= end; scanlineX++){
		drawLineVerticalClipped(cury1>>16,cury2>>16,scanlineX, col);
		cury1 += invslope1;
		cury2 += invslope2;
	}
}

INLINE void drawLeftFlatTriangleClipped(vec2 v0,vec2 v1,vec2 v2, u16 col){
	if (v0.y > v1.y){
		std::swap(v0,v1);
	}
	
	int difx = (v2.x - v0.x);
	
	int invslope1 = (v2.y - v0.y) / difx;
	int invslope2 = (v2.y - v1.y) / difx;
	int cury1 = v2.y;
	int cury2 = v2.y;
	
	if (v2.x >= SCREEN_WIDTH){
		int diff = v2.x-SCREEN_WIDTH+1;
		cury1 -= invslope1*diff;
		cury2 -= invslope2*diff;
	}
	
	int end = max(v0.x+1,0);
	for (int scanlineX = min(v2.x,SCREEN_WIDTH-1); scanlineX >= end; scanlineX--){
		drawLineVerticalClipped(cury1>>16,cury2>>16,scanlineX, col);
		cury1 -= invslope1;
		cury2 -= invslope2;
	}
}

void IWRAM_CODE drawTriangleClipped(const Poly &tri){
	vec2 v0,v1,v2;
	v0 = tri.v0;
	v1 = tri.v1;
	v2 = tri.v2;
	
	if (!clockwise(v2,v1,v0)){return;}
	
	//Sort the vertex list from bottom to top
	if (v0.x == max(v0.x,v1.x)){
		std::swap(v0,v1);
	}
	if (v1.x == max(v1.x,v2.x)){
		std::swap(v1,v2);
	}
	if (v0.x == max(v0.x,v1.x)){
		std::swap(v0,v1);
	}
	
	
	
	//check for trivial case of bottom-flat triangle
	if (v1.x == v2.x){
		drawRightFlatTriangleClipped(v0,v1,v2, tri.col);
	}
	//check for trivial case of top-flat triangle 
	else if (v0.x == v1.x){
		drawLeftFlatTriangleClipped(v0,v1,v2, tri.col);
	} 
	else{
		//general case - split the triangle in a topflat and bottom-flat one
		int lerpmult = ((v1.x - v0.x)<<16) / (v2.x - v0.x);
		vec2 v3{v1.x, v0.y + lerpmult*((v2.y - v0.y)>>16)};
		drawRightFlatTriangleClipped(v0,v1,v3, tri.col);
		drawLeftFlatTriangleClipped(v1,v3,v2, tri.col);
	}
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Line drawing
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void drawLineLow(int x0,int y0, int x1,int y1, u16 col){
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	
	if (dy < 0){
		yi = -1;
		dy = -dy;
	}
	
	int D = 2*dy - dx;
	int y = y0;
	
	for (int x=x0; x<=x1; x++){
		drawPixel(x,y,col);
		
		if (D > 0){
			y += yi;
			D -= 2*dx;
		}
		
		D += 2*dy;
	}
}

void drawLineHigh(int x0,int y0, int x1,int y1, u16 col){
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	
	if (dx < 0){
		xi = -1;
		dx = -dx;
	}
	
	int D = 2*dx - dy;
	int x = x0;
	
	for (int y=y0; y<=y1; y++){
		drawPixel(x,y, col);
		
		if (D > 0){
			x += xi;
			D -= 2*dy;
		}
		
		D += 2*dx;
	}
}

void drawLine(int x0,int y0, int x1,int y1, u16 col){
	if (abs(y1 - y0) < abs(x1 - x0)){
		if (x0 > x1){
			drawLineLow(x1, y1, x0, y0, col);
		}
		else{
			drawLineLow(x0, y0, x1, y1, col);
		}
	}
	else{
		if (y0 > y1){
			drawLineHigh(x1, y1, x0, y0, col);
		}
		else{
			drawLineHigh(x0, y0, x1, y1, col);
		}
	}
}


























INLINE Vertex2D projectVertex(const Vertex3D& vert, const Camera& cam, const vec3& tpos, int rotation){
	vec2 pos2D = {vert.pos.x,vert.pos.y};
	
	//dpos = Vector2DRotateHalf(dpos, cam.dir);
	pos2D = vector2DRotate(pos2D, cam.invdir+rotation);
	pos2D.y -= vert.pos.z;
	
	//Model translation
	pos2D.x += tpos.x;
	pos2D.y += tpos.y-tpos.z;
	
	//Zoom
	pos2D.x *= cam.zoom;
	pos2D.y *= cam.zoom;
	
	/*
	//Get unrotated screen space
	pos2D.x -= cam.pos.x-tpos.x;
	pos2D.y -= cam.pos.y-(tpos.y-tpos.z);
	
	//Rotate and apply Z
	pos2D = Vector2DRotate(pos2D, cam.dir);
	pos2D.y -= vert.pos.z;*/
	
	//Translate to middle of screen
	pos2D.x += 59;
	pos2D.y += 79;
	
	//Shift
	pos2D.y = pos2D.y<<16;//shift for higher precision necessary on the x axis
	
	Vertex2D result;
	result.pos = pos2D;
	
	return result;
}

void IWRAM_CODE drawModel(const Model& mod, const Camera& cam){
	//Variables
	Poly3D polyWrld;
	Poly polyScrn;
	Vertex2D vert0,vert1,vert2;
	int i;
	vec2 ppos;
	vec3 tpos;
	
	//Project model position
	ppos = {mod.pos.x-cam.pos.x, mod.pos.y-cam.pos.y};
	ppos = vector2DRotate(ppos, cam.invdir);
	
	tpos = {ppos.x,ppos.y,mod.pos.z};
	
	for (i=0; i<mod.polycount; i++){
		polyWrld = mod.tris[i];
		
		vert0 = projectVertex(polyWrld.v0, cam, tpos, mod.dir);
		vert1 = projectVertex(polyWrld.v1, cam, tpos, mod.dir);
		vert2 = projectVertex(polyWrld.v2, cam, tpos, mod.dir);
		
		polyScrn.v0 = vert0.pos;
		polyScrn.v1 = vert1.pos;
		polyScrn.v2 = vert2.pos;
		polyScrn.col = polyWrld.col;
		
		if (insideViewVertical(polyScrn.v0,polyScrn.v1,polyScrn.v2)){
			drawTriangle(polyScrn);
		}
		else{
			drawTriangleClipped(polyScrn);
		}
	}
}