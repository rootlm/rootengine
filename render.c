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


void draw_sprite_ext(short dsprite,unsigned short dsfrm,float dsx,float dsy,float dxsc,float dysc,short dsrot) {
SDL_Rect* dspriterect; //Destination rectangle (accounts for x and y scale, but origin can only be center right now)
	dspriterect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	dspriterect->w=SpriteData[dsprite].framerect.w * dxsc;
	dspriterect->h=SpriteData[dsprite].framerect.h * dysc;
	dspriterect->x=dsx-(dspriterect->w / 2); //center origin
	dspriterect->y=dsy-(dspriterect->h / 2); //see above
SDL_Rect* dspritefrect; //Copy of the framerect that it uses for animation
	dspritefrect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	dspritefrect->w=SpriteData[dsprite].framerect.w;
	dspritefrect->h=SpriteData[dsprite].framerect.h;
	dspritefrect->x=SpriteData[dsprite].framerect.x;
	if (SpriteData[dsprite].animlength == 0) {
		dsfrm = 0; //modulo by 0 means rip so 
	}
	if (dsfrm > SpriteData[dsprite].animlength) {
		dsfrm = dsfrm % SpriteData[dsprite].animlength; //make sure the frame number is within the animation length!
	}
	dspritefrect->x += SpriteData[dsprite].framerect.w * dsfrm;
	dspritefrect->y=SpriteData[dsprite].framerect.y;

	SDL_RenderCopyEx(renderer,SpriteData[dsprite].sheet,dspritefrect,dspriterect,dsrot,NULL,SDL_FLIP_NONE);
	if (dspriterect != NULL) {
		free(dspriterect);
	}
	if (dspritefrect != NULL) {
	free(dspritefrect);
	}
}