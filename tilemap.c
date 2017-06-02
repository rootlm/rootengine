#include "tilemap.h"
#include <SDL.h>
#include <SDL_rwops.h>
#include "math.h"
#include "sprtypes.h"
#include "render.h"
#include "globaldef.h"
#include "collision.h"
void InitTiles() {
MAPWIDTH = (unsigned short *) malloc(sizeof(unsigned short));
*MAPWIDTH = 8;
MAPHEIGHT = (unsigned short *) malloc(sizeof(unsigned short));
*MAPHEIGHT = 8;
TileArray = (char *) calloc(*MAPWIDTH * *MAPHEIGHT,sizeof(char));


view_x = (long *) malloc(sizeof(long));
view_y = (long *) malloc(sizeof(long));
*view_x = 0;
*view_y = 0;
view_scale = (float *) malloc(sizeof(float));


//Tile type collision boxes
TileTypeCollision = (hitbox*) calloc(255,sizeof(hitbox));
TileTypeCollision[1].lines = (float *) calloc(21,sizeof(float)); //solid box
TileTypeCollision[1].numlines=4;
TileTypeCollision[1].lines[1]=0; //1
TileTypeCollision[1].lines[2]=0;
TileTypeCollision[1].lines[3]=15;
TileTypeCollision[1].lines[4]=0;
TileTypeCollision[1].lines[5]=1;
TileTypeCollision[1].lines[6]=0; //2
TileTypeCollision[1].lines[7]=0;
TileTypeCollision[1].lines[8]=0;
TileTypeCollision[1].lines[9]=15;
TileTypeCollision[1].lines[10]=1;
TileTypeCollision[1].lines[11]=15; //3
TileTypeCollision[1].lines[12]=0;
TileTypeCollision[1].lines[13]=15;
TileTypeCollision[1].lines[14]=15;
TileTypeCollision[1].lines[15]=-1;
TileTypeCollision[1].lines[16]=0; //4
TileTypeCollision[1].lines[17]=15;
TileTypeCollision[1].lines[18]=15;
TileTypeCollision[1].lines[19]=15;
TileTypeCollision[1].lines[20]=-1;

TileTypeCollision[2].lines = (float *) calloc(16,sizeof(float)); //11 degree > part 1
TileTypeCollision[2].numlines=3;
TileTypeCollision[2].lines[1]=0; //1
TileTypeCollision[2].lines[2]=15;
TileTypeCollision[2].lines[3]=15;
TileTypeCollision[2].lines[4]=11.25;
TileTypeCollision[2].lines[5]=1;
TileTypeCollision[2].lines[6]=15; //2
TileTypeCollision[2].lines[7]=15;
TileTypeCollision[2].lines[8]=15;
TileTypeCollision[2].lines[9]=11.25;
TileTypeCollision[2].lines[10]=-1;
TileTypeCollision[2].lines[11]=0; //3
TileTypeCollision[2].lines[12]=15;
TileTypeCollision[2].lines[13]=15;
TileTypeCollision[2].lines[14]=15;
TileTypeCollision[2].lines[15]=-1;

TileTypeCollision[3].lines = (float *) calloc(21,sizeof(float)); //11 degree > part 2
TileTypeCollision[3].numlines=4;
TileTypeCollision[3].lines[1]=0; //1
TileTypeCollision[3].lines[2]=11.25;
TileTypeCollision[3].lines[3]=15;
TileTypeCollision[3].lines[4]=7.5;
TileTypeCollision[3].lines[5]=1;
TileTypeCollision[3].lines[6]=15; //2
TileTypeCollision[3].lines[7]=15;
TileTypeCollision[3].lines[8]=15;
TileTypeCollision[3].lines[9]=7.5;
TileTypeCollision[3].lines[10]=-1;
TileTypeCollision[3].lines[11]=0; //3
TileTypeCollision[3].lines[12]=15;
TileTypeCollision[3].lines[13]=15;
TileTypeCollision[3].lines[14]=15;
TileTypeCollision[3].lines[15]=-1;
TileTypeCollision[3].lines[16]=0; //3
TileTypeCollision[3].lines[17]=15;
TileTypeCollision[3].lines[18]=0;
TileTypeCollision[3].lines[19]=7.5;
TileTypeCollision[3].lines[20]=1;

TileTypeCollision[4].lines = (float *) calloc(21,sizeof(float)); //11 degree > part 3
TileTypeCollision[4].numlines=4;
TileTypeCollision[4].lines[1]=0; //1
TileTypeCollision[4].lines[2]=7.5;
TileTypeCollision[4].lines[3]=15;
TileTypeCollision[4].lines[4]=3.25;
TileTypeCollision[4].lines[5]=1;
TileTypeCollision[4].lines[6]=15; //2
TileTypeCollision[4].lines[7]=15;
TileTypeCollision[4].lines[8]=15;
TileTypeCollision[4].lines[9]=3.25;
TileTypeCollision[4].lines[10]=-1;
TileTypeCollision[4].lines[11]=0; //3
TileTypeCollision[4].lines[12]=15;
TileTypeCollision[4].lines[13]=15;
TileTypeCollision[4].lines[14]=15;
TileTypeCollision[4].lines[15]=-1;
TileTypeCollision[4].lines[16]=0; //3
TileTypeCollision[4].lines[17]=15;
TileTypeCollision[4].lines[18]=0;
TileTypeCollision[4].lines[19]=3.25;
TileTypeCollision[4].lines[20]=1;


TileTypeCollision[5].lines = (float *) calloc(21,sizeof(float)); //11 degree > part 4
TileTypeCollision[5].numlines=4;
TileTypeCollision[5].lines[1]=0; //1
TileTypeCollision[5].lines[2]=3.25;
TileTypeCollision[5].lines[3]=15;
TileTypeCollision[5].lines[4]=0;
TileTypeCollision[5].lines[5]=1;
TileTypeCollision[5].lines[6]=15; //2
TileTypeCollision[5].lines[7]=15;
TileTypeCollision[5].lines[8]=15;
TileTypeCollision[5].lines[9]=0;
TileTypeCollision[5].lines[10]=-1;
TileTypeCollision[5].lines[11]=0; //3
TileTypeCollision[5].lines[12]=15;
TileTypeCollision[5].lines[13]=15;
TileTypeCollision[5].lines[14]=15;
TileTypeCollision[5].lines[15]=-1;
TileTypeCollision[5].lines[16]=0; //3
TileTypeCollision[5].lines[17]=15;
TileTypeCollision[5].lines[18]=0;
TileTypeCollision[5].lines[19]=0;
TileTypeCollision[5].lines[20]=1;

TileTypeCollision[6].lines = (float *) calloc(16,sizeof(float));
TileTypeCollision[6].numlines=3;
TileTypeCollision[6].lines[1]=0; //1
TileTypeCollision[6].lines[2]=15;
TileTypeCollision[6].lines[3]=15;
TileTypeCollision[6].lines[4]=10;
TileTypeCollision[6].lines[5]=1;
TileTypeCollision[6].lines[6]=15; //2
TileTypeCollision[6].lines[7]=15;
TileTypeCollision[6].lines[8]=15;
TileTypeCollision[6].lines[9]=10;
TileTypeCollision[6].lines[10]=-1;
TileTypeCollision[6].lines[11]=0; //3
TileTypeCollision[6].lines[12]=15;
TileTypeCollision[6].lines[13]=15;
TileTypeCollision[6].lines[14]=15;
TileTypeCollision[6].lines[15]=-1;

TileTypeCollision[7].lines = (float *) calloc(21,sizeof(float));
TileTypeCollision[7].numlines=4;
TileTypeCollision[7].lines[1]=0; //1
TileTypeCollision[7].lines[2]=10;
TileTypeCollision[7].lines[3]=15;
TileTypeCollision[7].lines[4]=5;
TileTypeCollision[7].lines[5]=1;
TileTypeCollision[7].lines[6]=15; //2
TileTypeCollision[7].lines[7]=15;
TileTypeCollision[7].lines[8]=15;
TileTypeCollision[7].lines[9]=5;
TileTypeCollision[7].lines[10]=-1;
TileTypeCollision[7].lines[11]=0; //3
TileTypeCollision[7].lines[12]=15;
TileTypeCollision[7].lines[13]=15;
TileTypeCollision[7].lines[14]=15;
TileTypeCollision[7].lines[15]=-1;
TileTypeCollision[7].lines[16]=0; //3
TileTypeCollision[7].lines[17]=15;
TileTypeCollision[7].lines[18]=0;
TileTypeCollision[7].lines[19]=5;
TileTypeCollision[7].lines[20]=1;

TileTypeCollision[8].lines = (float *) calloc(21,sizeof(float));
TileTypeCollision[8].numlines=4;
TileTypeCollision[8].lines[1]=0; //1
TileTypeCollision[8].lines[2]=5;
TileTypeCollision[8].lines[3]=15;
TileTypeCollision[8].lines[4]=0;
TileTypeCollision[8].lines[5]=1;
TileTypeCollision[8].lines[6]=15; //2
TileTypeCollision[8].lines[7]=15;
TileTypeCollision[8].lines[8]=15;
TileTypeCollision[8].lines[9]=0;
TileTypeCollision[8].lines[10]=-1;
TileTypeCollision[8].lines[11]=0; //3
TileTypeCollision[8].lines[12]=15;
TileTypeCollision[8].lines[13]=15;
TileTypeCollision[8].lines[14]=15;
TileTypeCollision[8].lines[15]=-1;
TileTypeCollision[8].lines[16]=0; //3
TileTypeCollision[8].lines[17]=15;
TileTypeCollision[8].lines[18]=0;
TileTypeCollision[8].lines[19]=0;
TileTypeCollision[8].lines[20]=1;

TileTypeCollision[9].lines = (float *) calloc(16,sizeof(float)); // 22 degree > part 1
TileTypeCollision[9].numlines=3;
TileTypeCollision[9].lines[1]=0; //1
TileTypeCollision[9].lines[2]=15;
TileTypeCollision[9].lines[3]=15;
TileTypeCollision[9].lines[4]=7;
TileTypeCollision[9].lines[5]=1;
TileTypeCollision[9].lines[6]=15; //2
TileTypeCollision[9].lines[7]=7;
TileTypeCollision[9].lines[8]=15;
TileTypeCollision[9].lines[9]=15;
TileTypeCollision[9].lines[10]=-1;
TileTypeCollision[9].lines[11]=0; //3
TileTypeCollision[9].lines[12]=15;
TileTypeCollision[9].lines[13]=15;
TileTypeCollision[9].lines[14]=15;
TileTypeCollision[9].lines[15]=-1;

TileTypeCollision[10].lines = (float *) calloc(16,sizeof(float)); // 22 degree > part 2
TileTypeCollision[10].numlines=3;
TileTypeCollision[10].lines[1]=0; //1
TileTypeCollision[10].lines[2]=7;
TileTypeCollision[10].lines[3]=15;
TileTypeCollision[10].lines[4]=7;
TileTypeCollision[10].lines[5]=1;
TileTypeCollision[10].lines[6]=15; //2
TileTypeCollision[10].lines[7]=0;
TileTypeCollision[10].lines[8]=15;
TileTypeCollision[10].lines[9]=7;
TileTypeCollision[10].lines[10]=-1;
TileTypeCollision[10].lines[11]=0; //3
TileTypeCollision[10].lines[12]=7;
TileTypeCollision[10].lines[13]=15;
TileTypeCollision[10].lines[14]=7;
TileTypeCollision[10].lines[15]=-1;
/*printf("numlines:%i\n",TileTypeCollision[1].numlines);
printf("line 1 x2:%f\n",TileTypeCollision[1].lines[3]);
printf("lines pointer:%i\n",TileTypeCollision[1].lines);*/
TilesetTypes = (unsigned char*) calloc((TilesetWidth/16)*(TilesetHeight/16),sizeof(unsigned char));
*view_scale=0; //using this as an iterator cause lazy
while (*view_scale < ((TilesetWidth/16)*(TilesetHeight/16))) {
TilesetTypes[(int)*view_scale]=*view_scale;
*view_scale += 1;
}

}

void DrawTileMap() { //rudimentary version
SDL_Rect dtrect;
SDL_Rect dtrect2;
dtrect.w = 32;
dtrect.h = 32;
dtrect2.w = 32;
dtrect2.h = 32;
unsigned short dtmi = 0;
	while (dtmi < (*MAPWIDTH * *MAPHEIGHT)) {
	dtrect.x = (TileArray[dtmi] % (TilesetWidth/tilesize)) * tilesize; //framerect x
	dtrect.y = floor(TileArray[dtmi] / (TilesetWidth/tilesize)) * tilesize; //framerect y (replace y with length of tileset / tilesize later!!)
	dtrect.w = tilesize; //self explanatory
	dtrect.h = tilesize; //duh
	dtrect.x -= *view_x;
	dtrect.y -= *view_y;
	dtrect2.x = (dtmi % *MAPWIDTH) * tilesize; //destination x
	dtrect2.y = floor(dtmi / *MAPWIDTH) * tilesize; //destination y
	dtrect2.w = tilesize;
	dtrect2.h = tilesize;
	SDL_RenderCopyEx(renderer,SSheet_Tileset,&dtrect,&dtrect2,0,NULL,SDL_FLIP_NONE);
	dtmi += 1;
	}
}

void Engine_LoadMap(const char* loadmapfilename) {
SDL_RWops* mapfile = SDL_RWFromFile(loadmapfilename,"r");
	if (mapfile == NULL) {
		printf("Error loading map file %s!\n",loadmapfilename);
	}
	else {
		unsigned short i=0;
		*MAPWIDTH=SDL_ReadU8(mapfile);
		*MAPHEIGHT=SDL_ReadU8(mapfile);
		if (TileArray != NULL) { //if tile array exists erase it
			free(TileArray);
		}
		TileArray = (char *) calloc((*MAPWIDTH * *MAPHEIGHT),sizeof(char));
		while (i < *MAPWIDTH * *MAPHEIGHT) {
			TileArray[i]=SDL_ReadU8(mapfile);
			i+=1;
		}
		printf("Loaded map file %s successfully!\n",loadmapfilename);
		SDL_RWclose(mapfile);
	}
}

/*void DrawTileMap() { //uses view_scale but has pixel long gaps between tiles at some scales
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
	dtrect2.x = (dtmi % *MAPWIDTH) * (tilesize * *view_scale); //destination x
	dtrect2.y = floor(dtmi / *MAPWIDTH) * (tilesize * *view_scale); //destination y
	dtrect2.w = (tilesize * *view_scale);
	dtrect2.h = (tilesize * *view_scale);
	SDL_RenderCopyEx(renderer,SSheet_Tileset,&dtrect,&dtrect2,0,NULL,SDL_FLIP_NONE);
	dtmi += 1;
	}
}
*/
/*void DrawTileMap() { //rudimentary version
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

*/