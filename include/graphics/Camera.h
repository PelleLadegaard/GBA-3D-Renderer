#pragma once

#include "../utility/mathtypes.h"

class Camera{
public:
	Camera() : pos(vec2()), dir(0), invdir(0), zoom(0){}
	Camera(vec2 tPos, int tDir, int tZoom) : pos(tPos), dir(tDir), invdir(-tDir), zoom(tZoom) {}
	void move(int distance, int direction);
	void rotate(int direction);

	vec2 pos;
	int dir;
	int invdir;
	int zoom;
};