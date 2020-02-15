#include "../../include/utility/math.h"

#include "../../include/GBA/gba_video.h"

#include "../../include/utility/mathtypes.h"

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

// Calculate if the vertices are oriented in clockwise order, useful for backface culling
bool clockwise(vec2 v0, vec2 v1, vec2 v2){
    return (((v1.y - v0.y) * (v2.x - v1.x) -
              (v1.x - v0.x) * (v2.y - v1.y)) > 0);
}

// Inside view
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