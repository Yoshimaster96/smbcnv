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

float dot(vec3 a,vec3 b)
{
	return (a.x*b.x)+(a.y*b.y)+(a.z*b.z);
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
