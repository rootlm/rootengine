#include <SDL.h>
#ifndef __BFONT__
#define __BFONT__
typedef struct {
	SDL_Texture* fontimage;
	SDL_Rect* fontrects;
} BitmapFont;

BitmapFont* Engine_LoadFont(const char* fontfname);
void draw_text(BitmapFont* drawfont, short dtx, short dty, const char* drawstr);

#endif