#include "extmath.h"

int toInt(float f)
{
	return *(unsigned int *)&f;
}

int cnvAngle(float theta)
{
	return (int)(65536.0*theta/360.0);
}

float toDegrees(float theta)
{
	return 57.2957795130824*theta;
}

vec3 dotm(vec3 a,vec3 r0,vec3 r1,vec3 r2)
{
	float d0 = (a.x*r0.x)+(a.y*r1.x)+(a.z*r2.x);
	float d1 = (a.x*r0.y)+(a.y*r1.y)+(a.z*r2.y);
	float d2 = (a.x*r0.z)+(a.y*r1.z)+(a.z*r2.z);
	return (vec3){d0,d1,d2};
}

float dot(vec3 a,vec3 b)
{
	return (a.x*b.x)+(a.y*b.y)+(a.z*b.z);
}

vec3 cross(vec3 a,vec3 b)
{
	float d0 = (a.y*b.z)-(a.z*b.y);
	float d1 = (a.z*b.x)-(a.x*b.z);
	float d2 = (a.x*b.y)-(a.y*b.x);
	return (vec3){d0,d1,d2};
}

vec3 normalize(vec3 v)
{
	vec3 retVal = v;
	float len = sqrtf((v.x*v.x)+(v.y*v.y)+(v.z*v.z));
	retVal.x /= len;
	retVal.y /= len;
	retVal.z /= len;
	return retVal;
}

vec3 hat(vec3 v)
{
	vec3 retVal = {-v.y,v.x,0.0};
	return retVal;
}

float reverse_angle(float c,float s)
{
	float a = toDegrees(asin(s));
	if(c<0.0) a = 180.0-a;
	if(fabs(c)<fabs(s))
	{
		a = toDegrees(acos(s));
		if(s<0.0) a = -a;
	}
	if(a<0.0)
	{
		if(a>-0.001) a=0.0;
		else a+= 360.0;
	}
	return a;
}
