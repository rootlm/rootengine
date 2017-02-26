#ifndef __OBJTYPES__
#define __OBJTYPES__

//Init object format/array pointer
typedef struct {
char type;
int x;
int y;
int dir;
float xspeed;
float yspeed;
char sprite_index;
char state;
//int* objrefstorage;
} object;

object* Objects;
void InitObjectArray();

signed short FindObjSlot();
signed short CreateObject(char cotype,int cox,int coy);
#endif