#include <SDL.h>
#include "render.h"
#include "bfont.h"

BitmapFont* Engine_LoadFont(const char* fontfname) {
	BitmapFont* loadfont;
	loadfont = (BitmapFont *) malloc(sizeof(BitmapFont));
	loadfont->fontimage=Engine_LoadGraphic(fontfname);
	SDL_RWops* loadfontrectsfile=SDL_RWFromFile("fontrects.rootfont","r");
		unsigned short fontnumchars;
		fontnumchars=SDL_ReadLE16(loadfontrectsfile);
		loadfont->fontrects= (SDL_Rect *) calloc(fontnumchars,sizeof(SDL_Rect));
		unsigned short fontloadi=0;
		while (fontloadi < fontnumchars) {
		loadfont->fontrects[fontloadi].x=SDL_ReadLE16(loadfontrectsfile);
		loadfont->fontrects[fontloadi].y=SDL_ReadLE16(loadfontrectsfile);
		loadfont->fontrects[fontloadi].w=SDL_ReadU8(loadfontrectsfile);
		loadfont->fontrects[fontloadi].h=SDL_ReadU8(loadfontrectsfile);
		fontloadi += 1;
		}
	SDL_RWclose(loadfontrectsfile);
return loadfont;
}

void draw_text(BitmapFont* drawfont, short dtx, short dty, const char* drawstr) {
	unsigned char i=0;
	SDL_Rect* drawcharrect;
	drawcharrect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	drawcharrect->x=dtx;
	drawcharrect->y=dty;
		//while (i <= 11) {
		while (drawstr[i] >= 32) {
			drawcharrect->w=drawfont->fontrects[drawstr[i]].w;
			drawcharrect->h=drawfont->fontrects[drawstr[i]].h;
			SDL_RenderCopyEx(renderer,drawfont->fontimage,&drawfont->fontrects[drawstr[i]],drawcharrect,0,NULL,SDL_FLIP_NONE);
			drawcharrect->x += drawcharrect->w;
		i+=1;
		}
	if (drawcharrect != NULL) {
		free(drawcharrect);
	}
}