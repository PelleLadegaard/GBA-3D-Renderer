#include "../include/GBA/gba.h"
#include "../include/graphics/rendering.h"

#include "../include/data/models.h"
 
int main(void){
	bool sync = true;

	//Initialize the camera
	Camera cam;
	cam.pos.x = 0;
	cam.pos.y = 0;
	cam.dir = 0;
	cam.invdir = 0;
	cam.zoom = 4;
	
	//Initialize screen
	setMode( MODE_5 | BG2_ENABLE );
    u16* dx = (u16*)0x4000020;
	u16* dmx = (u16*)0x4000022;
	u16* dy = (u16*)0x4000024;
	u16* dmy = (u16*)0x4000026;
	dx[0] = 0;
	dy[0] = 128;
	dmx[0] = 256;
	dmy[0] = 0;
	
	//Clear both buffers one time at start
	clearBuffer();
	swapBuffers();
	clearBuffer();
	swapBuffers();
	
	int rotate = 0;
	//Model testmodel(164,mod_road, vec3{0,0,0},0);
	//model testmodel(160,mod_cliff, vec3{0,0,0},0);
	//Model testmodel(181,mod_city, vec3{0,0,0},0);
	Model testmodel(177,mod_city_fixed, vec3{0,0,0},0);
	
	while (true){
		if (sync){
			//Input
			int spd = 5;
			if (keyDown(KEY_L)){
				cam.dir -= 5;
				cam.invdir += 5;
			}
			if (keyDown(KEY_R)){
				cam.dir += 5;
				cam.invdir -= 5;
			}
			if (keyDown(KEY_UP)){
				moveCamera(cam, spd, cam.dir-64);
			}
			if (keyDown(KEY_DOWN)){
				moveCamera(cam, spd, cam.dir+64);
			}
			if (keyDown(KEY_LEFT)){
				moveCamera(cam, spd, cam.dir+128);
			}
			if (keyDown(KEY_RIGHT)){
				moveCamera(cam, spd, cam.dir);
			}
			
			clearBuffer();
			
			drawModel(testmodel, cam);
			
			sync = false;
		}
		else{
			if (REG_VCOUNT > 159){
				sync = true;
				swapBuffers();
			}
		}
		
	}

    return 0;
}