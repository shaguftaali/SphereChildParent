#pragma once
#include "3D/Object.h"

class Torus: public Object
{
public:
	Torus(const char * vertexPath, const char * fragmentPath, Vector3 position, float a_outter_radius, float a_inner_radius, int a_x_Sections, int a_y_Sections, Node* a_parent);
	void Render(const Camera& camera) override;
	static  Torus Test();
private:
	float outterRadius;
	float innerRadius;
	int x_Sections;
	int y_Sections;
protected:
	void SetVertices() override;
	void SetIndices() override;
	void SetDrawingData() override;
	void SetNormal() override;
};
