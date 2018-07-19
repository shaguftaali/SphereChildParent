#include "..\..\Includes\Maths\Vector4.h"

Vector4::Vector4():
	x(0),
	y(0),
	z(0),
	w(0)
{
	SetArray();
}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w):
	x(a_x),
	y(a_y),
	z(a_z),
	w(a_w)
{
	SetArray();
}

Vector4::Vector4(Vector3 vec3, float a_w):
	x(vec3.x),
	y(vec3.y),
	z(vec3.z),
	w(a_w)
{
	SetArray();
}

void Vector4::SetArray()
{
	arr[0]=x;
	arr[1] = y;
	arr[2] = z;
	arr[3] = w;
}
