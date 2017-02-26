#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "render.h"
#include "globaldef.h"
#include "sprtypes.h"

void InitWindow() {

//Initialize SDL
if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
{
printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
}
else
	{
	printf("SDL Initialized!\n");
	//Create window
	window = SDL_CreateWindow( APPTITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
	else
	{
	printf("Window created successfully!\n");
	//Get window surface
	screenSurface = SDL_GetWindowSurface( window );
	}
}

renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

if( renderer == NULL )
		{
		printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
		}

else {
printf("Renderer created successfully!\n");
}

SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

}

//=======================================================
//Load graphics function

SDL_Texture* Engine_LoadGraphic(const char* loadgfxfilename) {

SDL_Texture* newTexture = NULL;

SDL_Surface* loadedSurface = IMG_Load(loadgfxfilename);

newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

if (newTexture == NULL) {
printf( "Texture %s could not be created! SDL_Error: %s\n", loadgfxfilename, SDL_GetError() );
}

else {
printf( "Texture %s loaded! \n", loadgfxfilename );
}

SDL_FreeSurface(loadedSurface);

return newTexture;

}

void InitSDLImage() {
int initimgflags=IMG_INIT_PNG;
IMG_Init(initimgflags);
}

void draw_sprite_ext(short dsprite,long dsx,long dsy,float dxsc,float dysc,short dsrot) {
SDL_Rect dspriterect;
dspriterect.w=SpriteData[dsprite].framerect.w * dxsc;
dspriterect.h=SpriteData[dsprite].framerect.h * dysc;
short divw = dspriterect.w / 2;
short divy = dspriterect.h / 2;
dspriterect.x=dsx-divw;
dspriterect.y=dsy-divy;
/*SDL_Rect dspritefrect;
dspritefrect.x=SpriteData[dsprite].framerect.x;
dspritefrect.y=SpriteData[dsprite].framerect.y;
dspritefrect.w=SpriteData[dsprite].framerect.w;
dspritefrect.h=SpriteData[dsprite].framerect.h;*/
//&SpriteData[dsprite].framerect
SDL_RenderCopyEx(renderer,SpriteData[dsprite].sheet,&SpriteData[dsprite].framerect,&dspriterect,dsrot,NULL,SDL_FLIP_NONE);
}

//THIS IS WHY C IS TERRIBLE GOD FUCKING DAMMIT JUST STOP CRASHING JESUS CHRIST HOLY FUCKING BALLS
/*void draw_sprite_ext(short dsprite,short dsfrm,long dsx,long dsy,float dxsc,float dysc,short dsrot) {
SDL_Rect dspriterect;
dspriterect.w=SpriteData[dsprite].framerect.w * dxsc;
dspriterect.h=SpriteData[dsprite].framerect.h * dysc;
short* divw;
divw = (short *) malloc(sizeof(short));
*divw = dspriterect.w / 2;
short* divy;
divy = (short *) malloc(sizeof(short));
*divy = dspriterect.h / 2;
dspriterect.x=dsx - *divw;
dspriterect.y=dsy - *divy;
SDL_Rect* dspritefrect;
dspritefrect = (SDL_Rect*) malloc(sizeof(SDL_Rect));
dspritefrect->x=SpriteData[dsprite].framerect.x;
dspritefrect->y=SpriteData[dsprite].framerect.y;
dspritefrect->w=SpriteData[dsprite].framerect.w;
dspritefrect->h=SpriteData[dsprite].framerect.h;
	dspritefrect->x += dspritefrect->w * (dsfrm % SpriteData[dsprite].animlength);
if (divw != NULL) {
free(divw);
}
if (divy != NULL) {
free(divy);
}
//&SpriteData[dsprite].framerect
SDL_RenderCopyEx(renderer,SpriteData[dsprite].sheet,dspritefrect,&dspriterect,dsrot,NULL,SDL_FLIP_NONE);
if (dspritefrect != NULL) {
free(dspritefrect);
}
}*/