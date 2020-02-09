#pragma once

#include "mathtypes.h"
#include "lookups.h"

template <class T>
INLINE T IWRAM_CODE  max (T a, T b) {
  return (a>b?a:b);
}
template <class T>
INLINE T IWRAM_CODE  min (T a, T b) {
  return (a<b?a:b);
}

INLINE int cosLut(int value, int angle){
	return (value*(int)lut_cos[angle&0xff])>>8;
}
INLINE int sinLut(int value, int angle){
	return (value*(int)lut_sin[angle&0xff])>>8;
}

template <class T>
T lerp(T v0, T v1, T t) {
	return ((65536 - t<<16) * v0<<16 + t<<16 * v1<<16)>>16;
}

//Vector rotation
vec2 IWRAM_CODE vector2DRotate(vec2 v, int dir){
	//Dir must be a value between 0-255
	int cs = (int)lut_cos[dir & 0xff];
	int sn = (int)lut_sin[dir & 0xff];
	
	return {(v.x*cs - v.y*sn)>>8, 
			(v.x*sn + v.y*cs)>>8};
}
vec2 vector2DRotateHalf(vec2 v, int dir){
	//Dir must be a value between 0-255
	int cs = (int)lut_coshalf[dir & 0xff];
	int sn = (int)lut_sin[dir & 0xff];
	
	return {(v.x*cs - v.y*sn)>>8, 
			(v.x*sn + v.y*cs)>>8};
}

bool clockwise(vec2 v0, vec2 v1, vec2 v2){
    return (((v1.y - v0.y) * (v2.x - v1.x) -
              (v1.x - v0.x) * (v2.y - v1.y)) > 0);
}

//Inside view
bool insideViewHorizontal(vec2 v0, vec2 v1, vec2 v2){
	int maxx = max(max(v0.x,v1.x),v2.x)>>16;
	int minx = min(min(v0.x,v1.x),v2.x)>>16;
	int maxy = max(max(v0.y,v1.y),v2.y);
	int miny = min(min(v0.y,v1.y),v2.y);
	
	return (maxx < SCREEN_WIDTH && minx >= 0 && maxy < SCREEN_HEIGHT && miny >= 0);
}
bool insideViewVertical(vec2 v0, vec2 v1, vec2 v2){
	int maxx = max(max(v0.x,v1.x),v2.x);
	int minx = min(min(v0.x,v1.x),v2.x);
	int maxy = max(max(v0.y,v1.y),v2.y)>>16;
	int miny = min(min(v0.y,v1.y),v2.y)>>16;
	
	return (maxx < SCREEN_WIDTH && minx >= 0 && maxy < SCREEN_HEIGHT && miny >= 0);
}
bool insideView(vec2 v0, vec2 v1, vec2 v2){
	int maxx = max(max(v0.x,v1.x),v2.x);
	int minx = min(min(v0.x,v1.x),v2.x);
	int maxy = max(max(v0.y,v1.y),v2.y);
	int miny = min(min(v0.y,v1.y),v2.y);
	
	return (maxx < SCREEN_WIDTH && minx >= 0 && maxy < SCREEN_HEIGHT && miny >= 0);
}