#ifndef EXTMATH_H
#define EXTMATH_H

#include <math.h>

typedef struct
{
	float x;
	float y;
	float z;
} vec3;

typedef struct
{
	vec3 r0;
	vec3 r1;
	vec3 r2;
} mat3;

int toInt(float f);
int cnvAngle(float theta);
float toDegrees(float theta);
float dot(vec3 a,vec3 b);
vec3 normalize(vec3 v);
vec3 hat(vec3 v);
float reverse_angle(float c,float s);

#endif
