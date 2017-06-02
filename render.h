#include <SDL.h>
#ifndef __RENDER__
#define __RENDER__
SDL_Renderer* renderer;

//The window we'll be rendering to
SDL_Window* window;

//The surface contained by the window
SDL_Surface* screenSurface;

//The game surface
SDL_Texture* GAME_SURFACE;

void InitWindow();
void draw_sprite_ext(short dsprite,unsigned short dsfrm,float dsx,float dsy,float dxsc,float dysc,short dsrot);
void draw_sprite_view_ext(short dsprite,unsigned short dsfrm,float dsx,float dsy,float dxsc,float dysc,short dsrot);
void draw_sprite(short dsprite,unsigned short dsfrm,float dsx,float dsy);
void draw_sprite_view(short dsprite,unsigned short dsfrm,float dsx,float dsy);
SDL_Texture* Engine_LoadGraphic(const char* loadgfxfilename);
#endif