#include "Physics/Collision/IntersectData.h"

IntersectData::IntersectData(const bool a_doesIntersect, const float a_distance):
m_doesIntersect(a_doesIntersect),
m_distance(a_distance)
{}

bool IntersectData::GetDoesIntersect()
{
	return m_doesIntersect;
}



float IntersectData::GetDistance()
{
	return m_distance;
}
