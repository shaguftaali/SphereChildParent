#include "..\..\Includes\Shapes\Circle.h"

#define PI 3.14

Circle::Circle(const char * vertexPath, const char * fragmentPath, Vector3 a_position, float m_radius, int a_totalSections, Node* a_parent):
	Object(vertexPath, fragmentPath, a_position,a_parent),
	radius(m_radius),
	totalSections(a_totalSections)
{
	
	SetVertices();
	SetIndices();
	SetDrawingData();
}

void Circle::Render(const Camera & camera)
{
	Object::Render(camera);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Circle::SetVertices()
{
	float thea=0;
	Vector3 center=transform.position;
	vertices.push_back(center.x);
	vertices.push_back(center.y);
	vertices.push_back(center.z);

	for(int i=0;i<totalSections;i++)
	{
		float x= center.x+radius*cos(thea);
		float y= center.y+radius*sin(thea);

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(center.z);
		thea += 2.0f*PI / totalSections;
	}

}

void Circle::SetIndices()
{
	for (int i = 0; i < totalSections; i++)
	{
		indices.push_back(i+1);
		indices.push_back(0);
		if(i==totalSections-1)
		{
			indices.push_back(1);
		}
		else
		{
			indices.push_back(i + 2);
		}

	}
}

void Circle::SetDrawingData()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(vertices.size()), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*(indices.size()), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}
