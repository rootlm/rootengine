#include "objtypes.h"
#include "globaldef.h"
//void UselessFunction() {
//printf("USELESS FUNCTION YAY");
//}

//InitObjectArray:exactly what it sounds like
void InitObjectArray() {
Objects = (object*) calloc(MAXOBJECTS,sizeof(object));
}

signed short FindObjSlot() {
short fsi;
fsi = 0;

char fsdone;
fsdone = 0;

signed short fsret;
fsret = 0;

while (fsdone == 0) {
	if (Objects[fsi].type == 0) {
	fsdone=1;
	fsret=fsi;
	}

	else {
	fsi += 1;
	}

	if (fsi >= MAXOBJECTS+1) {
	fsdone = 1;
	fsret = -1;
	}
}

return fsret;
}

signed short CreateObject(char cotype,int cox,int coy) {
short coi;
coi = 0;

signed short slot;
slot = FindObjSlot();

//printf("CreateObject Slot:%i\n",slot);

if (slot != -1) {

Objects[slot].type = cotype;
Objects[slot].x = cox;
Objects[slot].y = coy;
Objects[slot].sprite_index = 0;
Objects[slot].state = 0;

	//player shot
	if (cotype == 2) {
	Objects[slot].yspeed = -10;
	Objects[slot].sprite_index = 1;
	}

}

else {
printf("Error! No more object slots available! \n");
}

return slot;

}