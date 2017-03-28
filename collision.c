#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "collision.h"
/*
DOCUMENTATION!
polygons should be composed of a number of lines in an array, formatted as such:
x1,y1,x2,y2,top/bottom collision (-1 for above 1 for below)
line collision should be fed individual arrays of lines, formatted as above minus the top/bottom collision
polygon collision simply returns whether or not it collides
line collision returns WHERE it would collide, regardless of whether or not the lines actually extend far enough
both on the X axis
*/

bool point_in_shape(float *temp, float pointx, float pointy, float x2, float y2, int numoflines) { //exactly what it says on the tin
	float *trianglearray = (float*)malloc(16 * sizeof(float));
	int i = 1;
	while (i <= numoflines * 5) {
		trianglearray[i] = temp[i];
		i += 1;
	}
	i = 1;
	float height;
	float width;
	float slope;
	float yinter;
	float ycheck;
	float ycheck2;
	int continu;
	while (i <= numoflines) {
		continu = 0;
		height = trianglearray[(i * 5) - 1] - trianglearray[(i * 5) - 3];
		width = trianglearray[(i * 5) - 2] - trianglearray[(i * 5) - 4];
		if (width != 0) {
			slope = height / width;
			yinter = y2 - (x2*slope);
			if (height == 1) {
				yinter = 0;
			}
			if (trianglearray[(i * 5) - 4] != 0) {
				yinter -= trianglearray[(i * 5) - 4] * slope;
				trianglearray[(i * 5) - 2] -= trianglearray[(i * 5) - 4];
				trianglearray[(i * 5) - 4] = 0;
			}
			if (trianglearray[(i * 5) - 3] != 0) {
				yinter += trianglearray[(i * 5) - 3];
				trianglearray[(i * 5) - 1] -= trianglearray[(i * 5) - 3];
				trianglearray[(i * 5) - 3] = 0;
			}
			ycheck = (pointx*slope) + yinter;
			ycheck2 = pointy;
			if (trianglearray[i * 5] == 1) {
				if (ycheck2 >= ycheck) {
					continu = 1;
				}
			}
			if (trianglearray[i * 5] == -1) {
				if (ycheck2 <= ycheck) {
					continu = 1;
				}
			}
		}
		else {
			if (trianglearray[i * 5] == 1) {
				if (x2 >= trianglearray[i * 5 - 4]) {
					continu = 1;
				}
			}
			if (trianglearray[i * 5] == -1) {
				if (x2 <= trianglearray[i * 5 - 4]) {
					continu = 1;
				}
			}
		}
		i += 1;
		if (continu == 0) {
			i = numoflines + 1;
		}
	}
	free(trianglearray);
	trianglearray = NULL;

	return continu;
}

float linecol(float *lline1, float *lline2, float x12, float y12, float x22, float y22) { //check for collision between two lines
	float *line1 = (float*)malloc(5 * sizeof(float)); //copy these to temporary memory
	memcpy(line1, lline1, 5 * sizeof(float));
	float *line2 = (float*)malloc(5 * sizeof(float));
	memcpy(line2, lline2, 5 * sizeof(float));

	
	float x1 = x12;
	float y1 = y12;
	float x2 = x22;
	float y2 = y22;

	
	if (line1[1] != 0) {
		x1 += line1[1];
		line1[3] -= line1[1];
		line1[1] = 0;
	}
	

	if (line1[2] != 0) {
		y1 += line1[2];
		line1[4] -= line1[2];
		line1[2] = 0;
	}
	
	if (line2[1] != 0) {
		x2 += line2[1];
		line2[3] -= line2[1];
		line2[1] = 0;
	}
	
	if (line2[2] != 0) {
		y2 += line2[2];
		line2[4] -= line2[2];
		line2[2] = 0;
	}
	
	
	/*float height = line1[2] - line1[4];
	float width = line1[1] - line1[3];
	float slope = height / width;

	height = line2[2] - line2[4];
	width = line2[1] - line2[3];
	float slope2 = height / width;*/
	float slope = line1[4] / line1[3];
	float slope2 = line2[4] / line2[3];

	//printf("%f", line1[4]);

	float returnval = 1;

	float yintercept1 = y1 - (x1*slope);
	float yintercept2 = y2 - (x2*slope2);

	//printf("%f", slope2);

	if (slope == INFINITY) {
		returnval = slope2*(line1[1]+x1)+yintercept2;
	}
	if (slope2 == INFINITY) {
		returnval = slope*(line2[1]+x2)+yintercept1;
	}
	if ((slope != INFINITY) && (slope2 != INFINITY)) {
		returnval =  (yintercept2 - yintercept1) / (slope - slope2);
		printf("\n %f", slope);
		printf("\n %f", slope2);
		printf("\n %f", yintercept1);
		printf("\n %f", yintercept2);
		printf("\n %f \n", (yintercept2 - yintercept1) / (slope - slope2));
	}
	
	free(line1);
	line1 = NULL;
	printf("AAAA ");
	free(line2);
	line2 = NULL;
	//printf("%f",slope);

	return returnval;
}

bool check_collision(float *linearray1, float *linearray2, float x1, float y1, float x2, float y2, char numoflines1, char numoflines2) {
	char i = 1;
	float *line1 = (float*)malloc(5 * sizeof(float));
	float *line2 = (float*)malloc(5 * sizeof(float));
	while (i <= numoflines1) {
		line1[1] = linearray1[((5 * i) - 5) + 1];
		line1[2] = linearray1[((5 * i) - 5) + 2];
		line1[3] = linearray1[((5 * i) - 5) + 3];
		line1[4] = linearray1[((5 * i) - 5) + 4];

		float width2 = fabs(line1[3] - line1[1])+x1;

		char i2 = 1;

		while (i2 <= numoflines2) {
			line2[1] = linearray2[((5 * i2) - 5) + 1];
			line2[2] = linearray2[((5 * i2) - 5) + 2];
			line2[3] = linearray2[((5 * i2) - 5) + 3];
			line2[4] = linearray2[((5 * i2) - 5) + 4];

			float width = fabs(line2[3] - line2[1])+x2;

			float retval = fabs(linecol(line1, line2, x1, y1, x2, y2));
			if ((retval <= width + line2[1]) && (retval >= x2 + line2[1])) {
				//retval += y2;
				//turn 0;
				if ((retval <= width2 + line1[1]) && (retval >= x1 + line1[1])) {
					free(line1);
					free(line2);
					return 1;
				}
			}
			i2 += 1;
		}
		i += 1;
	}
	i = 1;
	while (i <= numoflines1 * 2) {
		bool col = point_in_shape(linearray2, linearray1[(i * 2) - 1] + x1, linearray1[i * 2] + y1, x2, y2, numoflines2);
		if (col == 1) {
			free(line1);
			free(line2);
			return 1;
		}
		i += 1;
	}

	if (numoflines1 >= 3) {
		i = 1;
		while (i <= numoflines2 * 2) {
			bool col = point_in_shape(linearray1, linearray2[(i * 2) - 1] + x2, linearray2[i * 2] + y2, x1, y1, numoflines1);
			if (col == 1) {
				free(line1);
				free(line2);;
				return 1;
			}
			i += 1;
		}
	}
	free(line1);
	free(line2);
	return 0;
}
