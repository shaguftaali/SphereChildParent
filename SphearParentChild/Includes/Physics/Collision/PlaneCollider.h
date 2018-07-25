#pragma once
#include "Maths/Vector3.h"
#include "IntersectData.h"
#include "BoundingSphere.h"


class PlaneCollider
{
public:
	PlaneCollider(const Vector3& normal, float distance);
	IntersectData IntersectSphere(const BoundingSphere& other) const;
	PlaneCollider Normalized() const;
	Vector3 GetNormal();
	float GetDistance();
private:
	const Vector3 m_normal;
	const float m_distance;
};
