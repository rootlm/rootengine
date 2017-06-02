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
#include "bfont.h"


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
SSheet_Tileset = Engine_LoadGraphic("SprTestTileset.png");


SDL_QueryTexture(SSheet_Tileset,NULL,NULL,&w,&h); //get width and height of tileset (duh)
TilesetWidth = w;
TilesetHeight = h;
printf("%i\n",TilesetWidth);
printf("%i\n",TilesetHeight);
printf("%i\n",(2 % (TilesetWidth/tilesize))*16);
printf("%i\n",floor(2/(TilesetHeight/tilesize))*16);

//---------------------

InitSpriteArray();
InitObjectArray();

printf("initializing tiles..");
InitTiles();

printf("loading map..");
Engine_LoadMap("DashEDMap.rootmap");

printf("loaded (duh)");


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


CreateObject(0,320,240); //test player
/*SDL_RWops* cfgfile=SDL_RWFromFile("config.dat","r");
	if (cfgfile == NULL) { //create config file if one doesn't exist
		cfgfile=SDL_RWFromFile("config.dat","w");
		SDL_WriteU8(cfgfile,2); //Resolution Scale
		SDL_RWclose(cfgfile);

	}
	else {
		char window_scale=SDL_ReadU8(cfgfile);
		SDL_RWclose(cfgfile);
		SDL_SetWindowSize(window,SCREEN_WIDTH*window_scale,SCREEN_HEIGHT*window_scale);
	}*/
BitmapFont* testfont=Engine_LoadFont("SprTestFont.png");

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

draw_text(testfont,0,0,"Hello World! FUCKASS FUCK SHIT TEST ASSSS 69420 haha benis XDDD lol");

//player (there isn't an object loop so eh)
if (keyboard_check(LeftButtonState)) {
	Objects[0].x -= 4 - keyboard_check(JumpButtonState)*2;
	}
	while (tile_meeting(1,Objects[0].x-8,Objects[0].y-8,TileTypeCollision[1].lines,TileTypeCollision[1].numlines)) {
	Objects[0].x+=1;
	}
	if (keyboard_check(RightButtonState)) {
	Objects[0].x += 4 - keyboard_check(JumpButtonState)*2;
	}
	while (tile_meeting(1,Objects[0].x-8,Objects[0].y-8,TileTypeCollision[1].lines,TileTypeCollision[1].numlines)) {
	Objects[0].x-=1;
	}
	if (keyboard_check(UpButtonState)) {
	Objects[0].y -= 4 - keyboard_check(JumpButtonState)*2;
	}
	while (tile_meeting(1,Objects[0].x-8,Objects[0].y-8,TileTypeCollision[1].lines,TileTypeCollision[1].numlines)) {
	Objects[0].y+=1;
	}
	if (keyboard_check(DownButtonState)) {
	Objects[0].y += 4 - keyboard_check(JumpButtonState)*2;
	}
	while (tile_meeting(1,Objects[0].x-8,Objects[0].y-8,TileTypeCollision[1].lines,TileTypeCollision[1].numlines)) {
	Objects[0].y-=1;
	}
//printf("FUCK");
/*printf("%hi\n",point_in_shape(TileTypeCollision[9].lines, Objects[0].x, Objects[0].y, 200, 240,TileTypeCollision[2].numlines));
SDL_RenderDrawLine(renderer, TileTypeCollision[9].lines[1]+200, TileTypeCollision[9].lines[2]+240, TileTypeCollision[9].lines[3]+200, TileTypeCollision[9].lines[4]+240);
SDL_RenderDrawLine(renderer, TileTypeCollision[9].lines[6]+200, TileTypeCollision[9].lines[7]+240, TileTypeCollision[9].lines[8]+200, TileTypeCollision[9].lines[9]+240);
SDL_RenderDrawLine(renderer, TileTypeCollision[9].lines[11]+200, TileTypeCollision[9].lines[12]+240, TileTypeCollision[9].lines[13]+200, TileTypeCollision[9].lines[14]+240);
*/

//if (tile_meeting(1,Objects[0].x,Objects[0].y,TileTypeCollision[1].lines,TileTypeCollision[1].numlines)) {
//printf("FUCK idk why FUCK since if this works its good but FUCK anyway cause why the FUCK not\n");
//}

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
