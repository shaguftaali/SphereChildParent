#include "..\..\..\Includes\Physics\Collision\PlaneCollider.h"
#include <cmath>

PlaneCollider::PlaneCollider(const Vector3 & normal, float distance):
m_normal(normal),
m_distance(distance)
{}

IntersectData PlaneCollider::IntersectSphere(const BoundingSphere & other) const
{
	float distanceFromSphereCenter=(float)fabs(Vector3::DotProduct(m_normal,other.GetCenter())+m_distance);
	float distanceFromSphere=distanceFromSphereCenter-other.GetRadius();
	return IntersectData(distanceFromSphereCenter<0,distanceFromSphere);
}

PlaneCollider PlaneCollider::Normalized() const
{
	float magnitude=m_normal.Magnitude();
	return PlaneCollider(m_normal/magnitude,m_distance/magnitude);
}

Vector3 PlaneCollider::GetNormal()
{
	return m_normal;
}

float PlaneCollider::GetDistance()
{
	return m_distance;
}
