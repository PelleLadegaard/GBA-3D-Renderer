//#include "rendering.h"

/*void model::draw(camera cam){
	//Variables
	poly3D polyWrld;
	poly polyScrn;
	vertex2D vert0,vert1,vert2;
	int i;
	vec2 ppos;
	vec3 tpos;
	
	//Project model position
	ppos = {pos.x-cam.pos.x, pos.y-cam.pos.y};
	ppos = Vector2DRotateInt(ppos, cam.dir);
	
	tpos = {ppos.x,ppos.y,pos.z};
	
	for (i=0; i<polycount; i++){
		polyWrld = tris[i];
		
		vert0 = project(cam, polyWrld.v0, dir, tpos);
		vert1 = project(cam, polyWrld.v1, dir, tpos);
		vert2 = project(cam, polyWrld.v2, dir, tpos);
		
		polyScrn.v0 = vert0.pos;
		polyScrn.v1 = vert1.pos;
		polyScrn.v2 = vert2.pos;
		polyScrn.col = polyWrld.col;
		
		if (InsideView(polyScrn.v0,polyScrn.v1,polyScrn.v2)){
			DrawTriangle(polyScrn);
		}
		else{
			DrawTriangleClipped(polyScrn);
		}
	}
}

vertex2D model::project(camera& cam, vertex3D& vert, int rotation, vec3 tpos){
	vec2 pos2D = {vert.pos.x,vert.pos.y};
	
	//dpos = Vector2DRotateIntHalf(dpos, cam.dir);
	pos2D = Vector2DRotateInt(pos2D, cam.dir+rotation);
	pos2D.y -= vert.pos.z;
	
	//Model translation
	pos2D.x += tpos.x;
	pos2D.y += tpos.y-tpos.z;
	
	//Zoom
	pos2D.x *= cam.zoom;
	pos2D.y *= cam.zoom;
	
	//Translate to middle of screen
	pos2D.x += 59;
	pos2D.y += 79;
	
	//Shift
	pos2D.x = pos2D.x<<16;//shift for higher precision necessary on the x axis
	
	vertex2D result;
	result.pos = pos2D;
	
	return result;
}*/