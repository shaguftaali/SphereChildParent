#include "..\..\Includes\Physics\PhysicsObject.h"
#include <cassert>

PhysicsObject::PhysicsObject(const Vector3 & position, const Vector3 & velocity):
m_position(position),
m_velocity(velocity)
{}

void PhysicsObject::Integrate(float delta)
{
	m_position=m_position+(m_velocity*delta);
}

void PhysicsObject::Test()
{
	PhysicsObject test(Vector3(0,1,0),Vector3(1,2,3));

	test.Integrate(20);

	Vector3 testPos = test.GetPosition();
	Vector3 testVel = test.GetVelocity();

	assert(testPos.x == 20.0f);
	assert(testPos.y == 41.0f);
	assert(testPos.z == 60.0f);

	assert(testVel.x == 1.0f);
	assert(testVel.y == 2.0f);
	assert(testVel.z == 3.0f);

}

Vector3 PhysicsObject::GetPosition()
{
	return m_position;
}

Vector3 PhysicsObject::GetVelocity()
{
	return m_velocity;
}
