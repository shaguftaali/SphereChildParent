#pragma once
#include "Maths/Vector3.h"

class PhysicsObject
{
public:

	PhysicsObject(const Vector3& position,const Vector3& velocity);

	void Integrate(float delta);

	static  void Test();

	Vector3 GetPosition();

	Vector3 GetVelocity();

private:
	Vector3 m_position;

	Vector3 m_velocity;
};
