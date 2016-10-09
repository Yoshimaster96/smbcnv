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

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float time;
} frame;

typedef struct
{
	float posx;
	float posy;
	float posz;
} center;

extern int startCount;
extern int goalCount;
extern int bumperCount;
extern int jamabarCount;
extern int bananaCount;
extern int ignoreCount;
extern int animCount;
start starts[16];
goal goals[16];
bumper bumpers[16];
jamabar jamabars[16];
banana bananas[16];
float fallOutPlane;
char ignoreList[80][80];
char animList[80][80];
int animFrameCount[80];
frame animFrame[80][256];
center animCenter[80];

void parseConfig(char * configpath);

#endif
