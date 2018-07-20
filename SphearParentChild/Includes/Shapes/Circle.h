#pragma once
#include "../3D/Object.h"

class Circle :public Object
{
public:

	Circle(const char * vertexPath, const char * fragmentPath, Vector3 position, float m_radius, int a_totalSections, Node* a_parent);
	//Sphere();
	void Render(const Camera& camera) override;
	//std::vector<float> vertices;
private:

	float radius;
	int totalSections;

protected:
	/*void SetVertices(Vector3 position,int totalSections) override;*/
	void SetVertices() override;
	void SetIndices() override;
	void SetDrawingData() override;

};
