#pragma once
#include "../../Includes/Maths/Vector3.h"
#include "../../Includes/Maths/Matrix4.h"
enum Axis
{
	X,
	Y,
	Z
};
class  Transform
{
public:
	Transform();
	Transform(const Vector3& a_position);
	Transform(const Vector3& a_position, const Vector3& a_rotation);
	Transform(const Vector3& a_position,const Vector3& a_rotation,const Vector3& a_scale);
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void Rotate(Vector3 axis,float angle);

	Matrix4 modelMatrix;
	void SetModelMatrix();
private:

};
