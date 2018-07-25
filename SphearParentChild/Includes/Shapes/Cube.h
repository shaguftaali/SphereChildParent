#pragma once
#include "3D/Object.h"

class Cube : public Object
{
public:

	Cube(const char * vertexPath, const char * fragmentPath, Vector3 position, float a_size, Node* a_parent);
	//Sphere();
	void Render(const Camera& camera) override;
	static  Cube Test();
private:

	float size;
	//float colorVertices[] = {
	//	// front
	//	-0.2, -0.1, -0.5,
	//	0.1, -0.2, -0.35,
	//	0.21,  0.23, -0.5,
	//	-0.2,  0.2, -0.5,

	//	-0.2, -0.2,  0.5 ,
	//	0.2, -0.2,  0.5 ,
	//	0.2,  0.2,  0.5 ,
	//	-0.2,  0.2,  0.5
	//};


protected:
	/*void SetVertices(Vector3 position,int totalSections) override;*/
	void SetVertices() override;
	void SetIndices() override;
	void SetDrawingData() override;
	void SetNormal() override;


};
