#pragma once
#include "../Maths/Vector3.h"
#include "../Maths/Matrix4.h"

class Camera
{
public:

	Vector3 position;
	Vector3 eyeDirection;
	Vector3 up;
	float far;
	float near;
	float FOV;
	Matrix4 viewMatrix;
	Matrix4 projectionMatrix;
	Camera(const Vector3& a_position, const Vector3& target,const float a_far,const float a_near,const float a_FOV);
private:
	void SetViewMatrix();
	void SetProjectionMatrix();
};
