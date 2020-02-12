#pragma once

#include "../utility/mathtypes.h"

//Polygon formats
class Poly{
public:
	vec2 v0, v1, v2;
	u16 col;
};
class Poly3D{
public:
	vec3 v0,v1,v2;
	u16 col;
	
	Poly3D(){}
	
	Poly3D(vec3 pos0,vec3 pos1,vec3 pos2,u16 tcol):
			  v0(pos0),
			  v1(pos1),
			  v2(pos2),
			  col(tcol){}
	Poly3D(int x0,int y0,int z0, int x1,int y1,int z1, int x2,int y2,int z2, u16 tcol):
			  v0(vec3(x0,y0,z0)),
			  v1(vec3(x1,y1,z1)),
			  v2(vec3(x2,y2,z2)),
			  col(tcol){}
};

// Model format
class Model{
public:
	Model(int tpolycount,const Poly3D* ttris, vec3 tpos,int tdir):
			polycount(tpolycount),tris(ttris), pos(tpos),dir(tdir){}
	
	int polycount;
	const Poly3D* tris;
	
	vec3 pos;
	int dir;
};