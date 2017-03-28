//Includes
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "input.h"
#include "sprtypes.h"
#include "objtypes.h"
#include "render.h"
#include "globaldef.h"
#include "math2.h"

#include "tilemap.h"
#include "collision.h"


//main loop flag
char quit = 0;

//event handler
SDL_Event evunion;
void EventHandler() {
	while (SDL_PollEvent(&evunion) != 0 )
	{
		//User requests quit
		if (evunion.type == SDL_QUIT)
		{
		quit = 1;
		}
	}
 
}

//=======================================================
//Main loop
int main( int argc, char* args[] )
{
InitWindow();
InitSDLImage();

InitKeys();

//Create game screen texture
GAME_SURFACE = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA4444,SDL_TEXTUREACCESS_TARGET,640,480);

//Load textures
SSheet_Bullets = Engine_LoadGraphic("SprBullets.png");
SSheet_Player = Engine_LoadGraphic("SprPlayer.png");
SSheet_Tileset = SSheet_Bullets;

//---------------------

InitSpriteArray();
InitObjectArray();

InitTiles();


float* sine;
sine = (float *) malloc(sizeof(float));

//some variables i used in a test game on an old version
signed short* tempobj; //used this to store ids of created objects to edit their variables at creation
tempobj = (signed short *) malloc(sizeof(signed short));

int* interval;
interval = (int *) malloc(sizeof(int));
*interval = 0;

signed short* obji; //used this in the object loop
obji = (signed short *) malloc(sizeof(signed short));

int* timer;
timer = (int *) malloc(sizeof(int));
*timer = 0;

//stuff to test the collision!
float *triarray = (float*)calloc(15, 15 * sizeof(float));
float *colline1 = (float*)calloc(4, 4 * sizeof(float));
float *colline2 = (float*)calloc(4, 4 * sizeof(float));

triarray[2] = 20;
triarray[3] = 20;
triarray[4] = 21;
triarray[5] = -1;
triarray[7] = 20;
triarray[8] = 10;
triarray[10] = 1;
triarray[11] = 10;
triarray[13] = 20;
triarray[14] = 21;
triarray[15] = 1;
colline1[4] = 40;
colline2[4] = 40;
colline1[1] = 0;
colline1[2] = 0;
colline1[3] = 60;

colline2[1] = 20;
colline2[2] = 0;
colline2[3] = 40;


CreateObject(0,320,240); //test player
//------------------------------------------GAME LOOP
while (quit == 0) {
SDL_SetRenderTarget(renderer,GAME_SURFACE);
SDL_RenderClear(renderer);
SDL_SetRenderDrawColor(renderer, 128, 128, 128, 0xFF);
SDL_RenderFillRect(renderer,NULL);
SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
EventHandler();
UpdateKeys();

DrawTileMap();
draw_sprite_ext(3,*timer / 6,320,240,2.5+dsin(*timer)*1.5,2.5+dsin(*timer)*1.5,dsin(*timer)*45);
*timer += 1;

//test collision!
SDL_RenderDrawLine(renderer, triarray[1], triarray[2], triarray[3], triarray[4]);
SDL_RenderDrawLine(renderer, triarray[6], triarray[7], triarray[8], triarray[9]);
SDL_RenderDrawLine(renderer, triarray[11], triarray[12], triarray[13], triarray[14]);
SDL_RenderDrawLine(renderer, 0, 0, 0, 0);
printf("%hi\n", point_in_shape(triarray, Objects[0].x, Objects[0].y, 0, 0,3));



//player (there isn't an object loop so eh)
if (keyboard_check(LeftButtonState)) {
	Objects[0].x -= 4 - keyboard_check(JumpButtonState)*2;
	}
	while (point_in_shape(triarray, Objects[0].x, Objects[0].y, 0, 0,3)) {
	Objects[0].x+=1;
	}
	if (keyboard_check(RightButtonState)) {
	Objects[0].x += 4 - keyboard_check(JumpButtonState)*2;
	}
	while (point_in_shape(triarray, Objects[0].x, Objects[0].y, 0, 0,3)) {
	Objects[0].x-=1;
	}
	if (keyboard_check(UpButtonState)) {
	Objects[0].y -= 4 - keyboard_check(JumpButtonState)*2;
	}
	while (point_in_shape(triarray, Objects[0].x, Objects[0].y, 0, 0,3)) {
	Objects[0].y+=1;
	}
	if (keyboard_check(DownButtonState)) {
	Objects[0].y += 4 - keyboard_check(JumpButtonState)*2;
	}
	while (point_in_shape(triarray, Objects[0].x, Objects[0].y, 0, 0,3)) {
	Objects[0].y-=1;
	}

draw_sprite_ext(SPR_PLAYER,*timer / 4,Objects[0].x,Objects[0].y,1,1,0);


SDL_SetRenderTarget(renderer,NULL);
SDL_RenderCopyEx(renderer,GAME_SURFACE,NULL,NULL,0,NULL,SDL_FLIP_NONE);


SDL_RenderPresent(renderer);

//SDL_Delay( 16 );
}


SDL_DestroyTexture(SSheet_Bullets);
SDL_DestroyTexture(SSheet_Player);
SDL_DestroyTexture(GAME_SURFACE);

SDL_DestroyRenderer(renderer);

//Destroy window
SDL_DestroyWindow( window );

IMG_Quit();

//Quit SDL subsystems
SDL_Quit();

return 0;
}
