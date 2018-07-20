#pragma once
#include <vector>
#include "..\Maths/Vector3.h"
#include "../3D/Object.h"

class Grid: public Object
{
	
	public:
		//Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath);
		Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath, const Vector3& a_position, const Vector3& rotation, const Vector3& scale, Node* a_parent);
		Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath, const Vector3& a_position, const Vector3& rotation, Node* a_parent);
		Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath, const Vector3& a_position, Node* a_parent);
		void Render(const Camera& camera) override;
	private:
		float gridSize;
		float cellCount=10;
		Vector3 position;
		///*std::vector<float> vertices;
	//	std::vector<int> indices;
protected:
		/*void SetVertices(Vector3 position,float a_gridSize) override;*/
	void SetVertices() override;
		void SetDrawingData() override;


};
