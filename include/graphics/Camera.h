#pragma once

#include "../GBA/gba_types.h"

#include "../utility/math.h"

class Camera{
public:
	vec2 pos;
	int dir;
	int invdir;
	int zoom;
};

void moveCamera(Camera& cam, int dist, int dir){
    cam.pos.x += cosLut(dist, dir);
	cam.pos.y += sinLut(dist, dir);
}