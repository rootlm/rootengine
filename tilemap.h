#include <SDL.h>
#ifndef __TILEMAP__
#define __TILEMAP__
char* TileArray;
unsigned short* MAPWIDTH;
unsigned short* MAPHEIGHT;
SDL_Texture* SSheet_Tileset;
void InitTiles();
void DrawTileMap();
#endif