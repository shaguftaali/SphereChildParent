#pragma once

class IntersectData
{
public:
	IntersectData(const bool a_doesIntersect,const float a_distance);
	bool GetDoesIntersect();
	float GetDistance();
private:
	bool m_doesIntersect;
	float m_distance;
};