#pragma once
#include <vector>
#include "../Maths/Vector3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include "../Maths/Transform.h"
#include "../Shader.h"
#include "Camera.h"
#include "Node.h"

class Object :public Node
{
public:
	Object(const char * vertexPath, const char * fragmentPath,Node* parent);
	Object(const char * vertexPath, const char * fragmentPath, const Vector3& position, const Vector3& rotation, const Vector3& scale, Node* parent);
	Object(const char * vertexPath, const char * fragmentPath, const Vector3& position, const Vector3& rotation, Node* parent);
	Object(const char * vertexPath, const char * fragmentPath, const Vector3& position, Node* parent);
	virtual void Render(const Camera& camera);
	void DeleteDrawingData();
	//Transform transform;
private:
protected:
	std::vector<float> vertices;
	std::vector<float> normal;
	std::vector<int> indices;
	unsigned int VBO, VAO, EBO;
	virtual void SetDrawingData() = 0;
	/*virtual void SetVertices(Vector3 position, float a_gridSize)=0;*/
	virtual void SetVertices() = 0;
	virtual void SetIndices();
	virtual void SetNormal();
	Shader shader;

};




