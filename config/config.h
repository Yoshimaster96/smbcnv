#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string.h>

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
} start;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	int type;
} goal;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float sclx;
	float scly;
	float sclz;
} bumper;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float sclx;
	float scly;
	float sclz;
} jamabar;

typedef struct
{
	float posx;
	float posy;
	float posz;
	int type;
} banana;

extern int startCount;
extern int goalCount;
extern int bumperCount;
extern int jamabarCount;
extern int bananaCount;
extern float fallOutPlane;
start starts[16];
goal goals[16];
bumper bumpers[16];
jamabar jamabars[16];
banana bananas[16];
char ignoreList[16][81];

void parseConfig(char * configpath);

#endif
