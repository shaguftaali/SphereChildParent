#include "Physics/Collision/BoundingSphere.h"

BoundingSphere::BoundingSphere(const Vector3 & a_center, float a_radius):
m_center(a_center),
m_radius(a_radius)
{}

IntersectData BoundingSphere::IntersectBoundingSphere(const BoundingSphere& other)
{
	float radiusDistance=m_radius+other.m_radius;
	float centerDistance=Vector3::Distance(other.GetCenter(),m_center);
	float distance=centerDistance-radiusDistance;
	return IntersectData(centerDistance<radiusDistance,distance);
}

Vector3 BoundingSphere::GetCenter() const
{
	return m_center;
}

float BoundingSphere::GetRadius() const
{
	return m_radius;
}
