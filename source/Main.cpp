#include "../include/GBA/gba.h"
#include "../include/graphics/rendering.h"
#include "../include/graphics/Model.h"
#include "../include/graphics/Camera.h"

#include "../include/data/models.h"
 
int main(void){
	bool sync = true;

	// Initialize the camera
	Camera cam(vec2(0,0), 31, 4);
	
	// Initialize screen
	setMode( MODE_5 | BG2_ENABLE );
    u16* dx = (u16*)0x4000020;
	u16* dmx = (u16*)0x4000022;
	u16* dy = (u16*)0x4000024;
	u16* dmy = (u16*)0x4000026;
	dx[0] = 0;
	dy[0] = 128;
	dmx[0] = 256;
	dmy[0] = 0;
	
	// Clear both buffers one time at start
	clearBuffer();
	swapBuffers();
	clearBuffer();
	swapBuffers();
	
	// Model initialization, select a line to uncomment to draw the model. Also make sure to uncomment the correct model data in include/data/models.h
	Model testmodel(164,mod_road, vec3(0,0,0),0);
	//model testmodel(160,mod_cliff, vec3(0,0,0),0);
	//Model testmodel(177,mod_city, vec3(0,0,0),0);
	
	while(true){
		// Game loop
		if (sync){
			// Input
			int spd = 5;
			if (keyDown(KEY_L)){
				cam.rotate(-1);
			}
			if (keyDown(KEY_R)){
				cam.rotate(1);
			}
			if (keyDown(KEY_UP)){
				cam.move(spd, cam.dir-64);
			}
			if (keyDown(KEY_DOWN)){
				cam.move(spd, cam.dir+64);
			}
			if (keyDown(KEY_LEFT)){
				cam.move(spd, cam.dir+128);
			}
			if (keyDown(KEY_RIGHT)){
				cam.move(spd, cam.dir);
			}
			
			clearBuffer();
			
			testmodel.draw(cam);
			
			sync = false;
		}
		// Vsync
		else{
			if (REG_VCOUNT > 159){
				sync = true;
				swapBuffers();
			}
		}
		
	}

    return 0;
}