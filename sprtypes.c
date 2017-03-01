#include "sprtypes.h"
#include "globaldef.h"

//InitSpriteArray:also exactly what it sounds like BUT it also sets all the sprites data so..
void InitSpriteArray() {
SpriteData = (sprite*) calloc(MAXSPRITES, sizeof(sprite));

//Sprite List
//0 = Player
SpriteData[0].framerect.x=0;
SpriteData[0].framerect.y=0;
SpriteData[0].framerect.w=32;
SpriteData[0].framerect.h=32;
SpriteData[0].animlength=0;
SpriteData[0].sheet=SSheet_Player;
//1 = Player Shot
SpriteData[1].framerect.x=0;
SpriteData[1].framerect.y=17;
SpriteData[1].framerect.w=15;
SpriteData[1].framerect.h=8;
SpriteData[1].animlength=0;
SpriteData[1].sheet=SSheet_Bullets;
//2 = Small Blue Bullet
SpriteData[2].framerect.x=0;
SpriteData[2].framerect.y=0;
SpriteData[2].framerect.w=16;
SpriteData[2].framerect.h=16;
SpriteData[2].animlength=0;
SpriteData[2].sheet=SSheet_Bullets;
//3 = Medium Yellow Bullet
SpriteData[3].framerect.x=16;
SpriteData[3].framerect.y=0;
SpriteData[3].framerect.w=32;
SpriteData[3].framerect.h=32;
SpriteData[3].animlength=2;
SpriteData[3].sheet=SSheet_Bullets;
//4 = Giant Red Bullet
SpriteData[4].framerect.x=48;
SpriteData[4].framerect.y=0;
SpriteData[4].framerect.w=64;
SpriteData[4].framerect.h=64;
SpriteData[4].animlength=0;
SpriteData[4].sheet=SSheet_Bullets;
}