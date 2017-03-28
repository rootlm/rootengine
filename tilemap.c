#include "tilemap.h"
#include <SDL.h>
#include "math.h"
#include "sprtypes.h"
#include "render.h"
#include "globaldef.h"
void InitTiles() {
MAPWIDTH = (unsigned short *) malloc(sizeof(unsigned short));
*MAPWIDTH = 8;
MAPHEIGHT = (unsigned short *) malloc(sizeof(unsigned short));
*MAPHEIGHT = 8;
TileArray = (char *) calloc(*MAPWIDTH * *MAPHEIGHT,sizeof(char));
	char tiniti = 0;
	while (tiniti < 64) {
	TileArray[tiniti] = (rand() % 2);
	tiniti += 1;
	}
	TileArray[1]=1;
	TileArray[2]=2;
	TileArray[3]=3;
	TileArray[4]=4;
	TileArray[5]=5;
//*view_x = (long *) malloc(sizeof(long));
//*view_y = (long *) malloc(sizeof(long));
}

void DrawTileMap() { //rudimentary version
SDL_Rect dtrect;
SDL_Rect dtrect2;
dtrect.w = 32;
dtrect.h = 32;
dtrect2.w = 32;
dtrect2.h = 32;
char dtmi = 0;
	while (dtmi < 64) {
	dtrect.x = (TileArray[dtmi] % *MAPWIDTH) * tilesize; //framerect x
	dtrect.y = floor(TileArray[dtmi] / 8) * tilesize; //framerect y (replace y with length of tileset / tilesize later!!)
	dtrect.w = tilesize; //self explanatory
	dtrect.h = tilesize; //duh
	dtrect2.x = (dtmi % *MAPWIDTH) * tilesize; //destination x
	dtrect2.y = floor(dtmi / *MAPWIDTH) * tilesize; //destination y
	dtrect2.w = tilesize;
	dtrect2.h = tilesize;
	SDL_RenderCopyEx(renderer,SSheet_Tileset,&dtrect,&dtrect2,0,NULL,SDL_FLIP_NONE);
	dtmi += 1;
	}
}

/*void DrawTileMap() {
SDL_Rect dtrect;
SDL_Rect dtrect2;
dtrect.w = 32;
dtrect.h = 32;
dtrect2.w = 32;
dtrect2.h = 32;
unsigned short dtmi = 0;
unsigned char lines;
*view_x = 0;
*view_y = 0;
	while (lines < 23) {
	dtmi = ((*view_x / tilesize) - 1) + (*MAPWIDTH * lines);
		while (dtmi < 45) {
			dtrect.x = (TileArray[dtmi] % *MAPWIDTH) * tilesize; //framerect x
			dtrect.y = floor(TileArray[dtmi] / 8) * tilesize; //framerect y (replace y with length of tileset / tilesize later!!)
			dtrect.w = tilesize; //self explanatory
			dtrect.h = tilesize; //duh
			dtrect2.x = (dtmi % *MAPWIDTH) * tilesize; //destination x
			dtrect2.y = floor(dtmi / *MAPWIDTH) * tilesize; //destination y
			dtrect2.w = tilesize;
			dtrect2.h = tilesize;
			SDL_RenderCopyEx(renderer,SSheet_Tileset,&dtrect,&dtrect2,0,NULL,SDL_FLIP_NONE);
			dtmi += 1;
		}
	}
}*/