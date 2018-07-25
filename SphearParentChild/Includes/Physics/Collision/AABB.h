#pragma once
#include "Maths/Vector3.h"
#include "IntersectData.h"

//Axis Aling Bounding Box
class AABB
{
public:
	AABB(const Vector3& minExtents, const Vector3& maxExtents);

	IntersectData IntersectAABB(const AABB& other);

	const Vector3& GetMinExtents() const;

	const Vector3& GetMaxExtents() const;

private:
	const Vector3 m_minExtents;
	const Vector3 m_maxExtents;
};