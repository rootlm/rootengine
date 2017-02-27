#include <math.h>

float degtorad(float degtoconv) {
return ((degtoconv * 3.14) / 180);
}

float radtodeg(float radtoconv) {
return ((radtoconv * 180) / 3.14);
}

float point_direction(int x1, int y1, int x2, int y2) {
return atan2(x2-x1, y2-y1);
}

float dsin(float dsinarg) {
return sin(degtorad(dsinarg));
}

float dcos(float dcosarg) {
return cos(degtorad(dcosarg));
}

float point_distance(x1,y1,x2,y2) {

	int xdist = (x1-x2);
	xdist = xdist * xdist;

	int ydist = (y1-y2);
	ydist = ydist * ydist;

return sqrt(xdist + ydist);
}