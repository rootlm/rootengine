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

//---------------------

InitSpriteArray();
InitObjectArray();


float* sine;
sine = (float *) malloc(sizeof(float));

//some variables i used in a test game on an old version
signed short* tempobj; //used this to store ids of created objects to edit their variables at creation
tempobj = (signed short *) malloc(sizeof(signed short));

int* interval;
interval = (int *) malloc(sizeof(int));
*interval = 0;

int* obji; //used this in the object loop
obji = (signed short *) malloc(sizeof(signed short));

int* timer;
timer = (int *) malloc(sizeof(int));
*timer = 0;

//printf("%.6f\n",dsin(180));
//printf("%.6f\n",sin(3.14));
//printf("%.6f\n",degtorad(180));


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

draw_sprite_ext(3,*timer / 6,320,240,2.5+dsin(*timer)*1.5,2.5+dsin(*timer)*1.5,rand()%360);
*timer += 1;
//printf("%i\n",*timer);

//player (there isn't an object loop so eh)
if (keyboard_check(LeftButtonState)) {
	Objects[0].x -= 4 - keyboard_check(JumpButtonState)*2;
	}
	if (keyboard_check(RightButtonState)) {
	Objects[0].x += 4 - keyboard_check(JumpButtonState)*2;
	}
	if (keyboard_check(UpButtonState)) {
	Objects[0].y -= 4 - keyboard_check(JumpButtonState)*2;
	}
	if (keyboard_check(DownButtonState)) {
	Objects[0].y += 4 - keyboard_check(JumpButtonState)*2;
	}

draw_sprite_ext(SPR_PLAYER,0,Objects[0].x,Objects[0].y,1,1,0);


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
