#pragma once
#include "Maths/Vector3.h"
#include "IntersectData.h"

class BoundingSphere
{
public:
	BoundingSphere(const Vector3& a_center,float a_radius);
	IntersectData IntersectBoundingSphere(const BoundingSphere& other);
	Vector3 GetCenter() const;
	float GetRadius() const;
private:
	const Vector3 m_center;
	const float m_radius;

};
