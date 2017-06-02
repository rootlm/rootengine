#include <stdbool.h>
#ifndef __COLLISION__
#define __COLLISION__
	typedef struct { //collision shape struct
	float* lines;
	//float lines[20];
	unsigned char numlines;
	} hitbox;
bool point_in_shape(float *temp, float pointx, float pointy, float x2, float y2, int numoflines);
float linecol(float *lline1, float *lline2, float x12, float y12, float x22, float y22);
bool check_collision(float *linearray1, float *linearray2, float x1, float y1, float x2, float y2, char numoflines1, char numoflines2);
bool tile_meeting(char tiletype,float x,float y,float *linearray1,char numoflines1);
#endif