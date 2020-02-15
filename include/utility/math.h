#pragma once

#include "lookups.h"

class vec2;
class vec3;

template <class T>
INLINE void swap (T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
INLINE T abs (T val) {
	return (val<(T)0 ? val*(T)-1 : val);
}

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
vec2 IWRAM_CODE vector2DRotate(vec2 v, int dir);
vec2 vector2DRotateHalf(vec2 v, int dir);

// Calculate if the vertices are oriented in clockwise order, useful for backface culling
bool clockwise(vec2 v0, vec2 v1, vec2 v2);

// Inside view
bool insideViewHorizontal(vec2 v0, vec2 v1, vec2 v2);
bool insideViewVertical(vec2 v0, vec2 v1, vec2 v2);
bool insideView(vec2 v0, vec2 v1, vec2 v2);