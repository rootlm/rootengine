#include <SDL.h>
#include "collision.h"
#ifndef __TILEMAP__
#define __TILEMAP__
char* TileArray;
unsigned short* MAPWIDTH;
unsigned short* MAPHEIGHT;
SDL_Texture* SSheet_Tileset;

int* w,h;
int TilesetWidth,TilesetHeight;

hitbox* TileTypeCollision; //the hitboxes for tile types
unsigned char* TilesetTypes; //tile types for each tile in a tileset (2d array, slot 1 is the tileset, slot 2/0 is tile type,2/1 is flags)

void InitTiles();
void DrawTileMap();
void Engine_LoadMap(const char* loadmapfilename);
#endif