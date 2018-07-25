#include "..\..\Includes\Physics\Collision\AABB.h"
#include <valarray>

AABB::AABB(const Vector3 & minExtents, const Vector3 & maxExtents):
m_minExtents(minExtents),
m_maxExtents(maxExtents)
{}

IntersectData AABB::IntersectAABB(const AABB & other)
{
	float dist1=Vector3::Distance(other.GetMaxExtents(),m_minExtents);
	float dist2=Vector3::Distance(other.GetMinExtents(),m_maxExtents);

	float dist=dist2-dist1;
	return IntersectData(dist<0,std::fabs(dist));
}

const Vector3 & AABB::GetMinExtents() const
{
	return m_minExtents;
}

const Vector3 & AABB::GetMaxExtents() const
{
	return  m_maxExtents;
}
