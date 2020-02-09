//
// Video memory setup
//
 
#pragma once
 
#include "gba_types.h"
#include "gba_regs.h"
 
//define the screen width and height values to be used
#define SCREEN_WIDTH     120
#define SCREEN_HEIGHT  	 160
 
#define MODE_0        0x0      //screen mode 0
#define MODE_1        0x1      //screen mode 1
#define MODE_2        0x2      //screen mode 2
#define MODE_3        0x3      //screen mode 3
#define MODE_4        0x4      //screen mode 4
#define MODE_5        0x5      //screen mode 5
 
#define backbuffer       0x10    //define the buffer which is used to set the 
                                               //active buffer(using double buffering)
 
#define H_BLANK_OAM      0x20    //This bit, when set allows OAM
//(Object Attribute memory) to be updated during a //horizontal blank
 
#define OBJ_MAP_2D           0x00    //Sprite data is stored in a 2D array(dont use this!!)
#define OBJ_MAP_1D           0x40    //Sprite data is stored in a 1D array
 
#define BG0_ENABLE           0x100  //Enables background 0
#define BG1_ENABLE           0x200  //Enables background 1
#define BG2_ENABLE           0x400  //Enables background 2
#define BG3_ENABLE           0x800  //Enables background 3
#define OBJ_ENABLE           0x1000            //Enables sprites
 
#define setMode(mode) REG_DISPCNT = (mode)
 
//Set the mode that you want to use, logical OR them together as below:
//e.g. SetMode(MODE_2 | OBJ_ENABLE | OBJ_MAP_1D);
