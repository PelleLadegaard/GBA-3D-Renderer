#include "../../include/graphics/Model.h"

#include "../../include/utility/math.h"
#include "../../include/graphics/rendering.h"
#include "../../include/graphics/Camera.h"

void IWRAM_CODE Model::draw(const Camera& cam){
        //Variables
        Poly3D polyWrld;
        Poly polyScrn;
        vec2 vert0,vert1,vert2;
        int i;
        vec2 ppos;
        vec3 tpos;
        
        //Project model position
        ppos = vec2(pos.x-cam.pos.x, pos.y-cam.pos.y);
        ppos = vector2DRotate(ppos, cam.invdir);
        
        tpos = vec3(ppos.x,ppos.y,pos.z);
        
        for (i=0; i<polycount; i++){
            polyWrld = tris[i];
            
            vert0 = projectVertex(polyWrld.v0, cam, tpos, dir);
            vert1 = projectVertex(polyWrld.v1, cam, tpos, dir);
            vert2 = projectVertex(polyWrld.v2, cam, tpos, dir);
            
            polyScrn.v0 = vert0;
            polyScrn.v1 = vert1;
            polyScrn.v2 = vert2;
            polyScrn.col = polyWrld.col;
            
            if (insideViewVertical(polyScrn.v0,polyScrn.v1,polyScrn.v2)){
                drawTriangle(polyScrn);
            }
            else{
                drawTriangleClipped(polyScrn);
            }
        }
    }