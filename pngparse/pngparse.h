#ifndef PNGPARSE_H
#define PNGPARSE_H

#include <png.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int r;
	int g;
	int b;
	int a;
} pixel;

typedef struct
{
	int width;
	int height;
	pixel pixels[65536];
} image;

image parsePng(char * pngpath);

#endif
