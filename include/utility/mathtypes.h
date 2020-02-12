#pragma once

class vec2{
public:
	vec2() : x(0), y(0){}
	vec2(const vec2 &o) : x(o.x), y(o.y) {}
	vec2(int tX, int tY) : x(tX), y(tY){}
	int x,y;
};
class vec3{
public:
	vec3() : x(0), y(0), z(0){}
	vec3(const vec3 &o) : x(o.x), y(o.y), z(o.z) {}
	vec3(int tX, int tY, int tZ) : x(tX), y(tY), z(tZ){}
	int x,y,z;
};