#pragma once

#include "../utility/mathtypes.h"

//Camera format
class Camera{
public:
	vec2 pos;
	int dir;
	int invdir;
	int zoom;
};

//Vertex format
class Vertex2D{
public:
	vec2 pos;
};
class Vertex3D{
public:
	vec3 pos;
};

//Polygon format
class Poly{
public:
	vec2 v0, v1, v2;
	u16 col;
};
class Poly3D{
public:
	Vertex3D v0,v1,v2;
	u16 col;
	
	Poly3D(){}
	
	Poly3D(vec3 pos0,vec3 pos1,vec3 pos2,u16 tcol):
			  v0({pos0}),
			  v1({pos1}),
			  v2({pos2}),
			  col(tcol){}
};

class Model{
public:
	Model(int tpolycount,const Poly3D* ttris, vec3 tpos,int tdir):
			polycount(tpolycount),tris(ttris), pos(tpos),dir(tdir){}
	
	int polycount;
	const Poly3D* tris;
	
	vec3 pos;
	int dir;
};