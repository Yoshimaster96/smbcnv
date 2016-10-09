#ifndef EXTMATH_H
#define EXTMATH_H

#include <math.h>

typedef struct
{
	float x;
	float y;
	float z;
} vec3;

float min3(float a,float b,float c);
float max3(float a,float b,float c);
int toInt(float f);
int cnvAngle(float theta);
float toDegrees(float theta);
vec3 dotm(vec3 a,vec3 r0,vec3 r1,vec3 r2);
float dot(vec3 a,vec3 b);
vec3 cross(vec3 a,vec3 b);
vec3 normalize(vec3 v);
vec3 hat(vec3 v);
float reverse_angle(float c,float s);

#endif
