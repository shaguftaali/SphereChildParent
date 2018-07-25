#include "..\..\Includes\Maths\Vector3.h"
#include <cassert>
#include <math.h>

Vector3::Vector3():
x(0),
y(0),
z(0)
{}

Vector3::Vector3(float m_x, float m_y, float m_z):
x(m_x),
y(m_y),
z(m_z)
{}

Vector3 Vector3::operator+(const Vector3 & vec)
{
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}



Vector3 Vector3::CrossProduct(const Vector3 & v1, const Vector3 & v2)
{
	float i = (v1.y*v2.z) - (v2.y*v1.z);
	float j = -(v1.x*v2.z) + (v2.x*v1.z);
	float k = (v1.x*v2.y) - (v2.x*v1.y);

	return Vector3(i, j, k);
}

float Vector3::DotProduct(const Vector3 & v1, const Vector3 & v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float Vector3::Distance(const Vector3 & v1, const Vector3 & v2)
{
	return Magnitude(v1-v2);
}

Vector3 Vector3::Normalization()
{
	return *this/Magnitude();
}

float Vector3::Magnitude() const
{
	return sqrtf(SqrMagnitude());
}

float Vector3::Magnitude(const Vector3 & vec3)
{
	return sqrtf(SqrMagnitude(vec3));
}

float Vector3::SqrMagnitude() const
{
	return (x*x + y*y + z*z);
}

float Vector3::SqrMagnitude(const Vector3 & vec3)
{
	return (vec3.x*vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
}
//
//Vector3 operator+(const Vector3 & v1, const Vector3 & v2)
//{
//	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
//}

Vector3 operator-(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

//Vector3 Vector3::operator-(const Vector3 & vec) const
//{
//	return Vector3(x - vec.x, y - vec.y, z - vec.z);
//}

Vector3 operator*(const float scaler, const Vector3 & vec3)
{
	return Vector3(scaler*vec3.x, scaler*vec3.y, scaler*vec3.z);
}

Vector3 Vector3::operator*(const float scaler)
{
	return Vector3(scaler*x,scaler*y,scaler*z);
}

Vector3 Vector3::operator/(const float scaler)
{
	return Vector3(x/scaler,y/scaler, z/scaler);
}

Vector3 operator/(const Vector3 & vec3, const float scaler)
{
	assert(scaler != 0 && "cant divide with zero");
	return Vector3(vec3.x / scaler, vec3.y / scaler, vec3.z / scaler);
}
