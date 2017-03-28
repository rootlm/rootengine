#ifndef __GLOBALDEF__
#define __GLOBALDEF__
//these are global defines (and variables now because 1 file is better)

//Screen dimension constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define coltypesize unsigned char //how many collision types there can be for tiles!
#define tilesize 16 //16x16 tiles!

#define APPTITLE "root engine"

//limits
//These define the size of the arrays that hold stuff
#define MAXOBJECTS 512
//There can't be any more sprites defined than this so CHANGE IT WHEN THE GAME HAS TOO MANY
#define MAXSPRITES 32

//Variables
long* view_x;
long* view_y;
long* view_w;
long* view_h;
long* view_scale;
#endif