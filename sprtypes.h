#include <SDL.h>

#ifndef __SPRTYPES__
#define __SPRTYPES__
//Init sprite format/array
typedef struct {
SDL_Rect framerect;
char animlength;
SDL_Texture* sheet;
} sprite;

//Define sprite names and corresponding numbers here
#define SPR_PLAYER 0

//define spritesheet pointers
SDL_Texture* SSheet_Bullets;

SDL_Texture* SSheet_Player;

sprite* SpriteData;
void InitSpriteArray();
#endif