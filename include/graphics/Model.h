#pragma once

#include "Polygon.h"

class Camera;

class Model{
public:
	Model(int tpolycount,const Poly3D* ttris, vec3 tpos,int tdir):
			polycount(tpolycount),tris(ttris), pos(tpos),dir(tdir){}
    
    void IWRAM_CODE draw(const Camera& cam);
	
	int polycount;
	const Poly3D* tris;
	
	vec3 pos;
	int dir;
};