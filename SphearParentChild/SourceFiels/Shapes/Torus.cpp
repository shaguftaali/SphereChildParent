#include "..\..\Includes\Shapes\Torus.h"

#define PI 3.14

Torus::Torus(const char * vertexPath, const char * fragmentPath, Vector3 a_position, float a_outter_radius, float a_inner_radius, int a_x_Sections, int a_y_Sections, Node * a_parent):
Object(vertexPath,fragmentPath,a_position,a_parent),
outterRadius(a_outter_radius),
innerRadius(a_inner_radius),
x_Sections(a_x_Sections),
y_Sections(a_y_Sections)
{
	SetVertices();
	SetIndices();
	SetNormal();
	SetDrawingData();
}

void Torus::Render(const Camera & camera)
{
	
	Object::Render(camera);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	shader.setVec3("lightPos", 0.0f, 0.0f, 50.0f);
	shader.setVec3("objectColor", 0.5f, 0.2f, 0.51f);
	shader.setVec3("lightColor", 1.0f, 0.5f, 1.0f);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

Torus Torus::Test()
{
	Torus torus(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(6.5, 0, 0),
		10,
		5,
		20,
		20,
		nullptr
	);

	return torus;
}

void Torus::SetVertices()
{
	float theta=0 ;
	for (int i=0;i<y_Sections;i++)
	{
		float phi=0;
		theta += 2 * PI / y_Sections;
		for (int j=0;j<x_Sections;j++)
		{
			phi += 2 * PI / x_Sections;
			float x=(outterRadius+innerRadius*cos(theta))*cos(phi);
			float y = (outterRadius + innerRadius * cos(theta))*sin(phi);
			float z = innerRadius * sin(theta);

			/*float y = i * 10;
			float x = j * 10;
			float z = 0;*/

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);
		}
	}
}

void Torus::SetIndices()
{
	float x_max=x_Sections;
	float y_max = y_Sections ;
	for (int i=0; i < y_max; i++)
	{
		
		for (int j=0; j < x_max; j++)
		{
			int index=(i*x_max)+j;
			if(i==y_max-1)
			{
				if (j == x_max - 1)
				{
					indices.push_back(index);
					indices.push_back(j);
					indices.push_back(i*x_max);

					indices.push_back(i*x_max);
					indices.push_back(j);
					indices.push_back(0);
				}
				else
				{
					
				indices.push_back(index);
				indices.push_back(j);
				indices.push_back(index + 1);

				indices.push_back(index+1);
				indices.push_back(j);
				indices.push_back(j + 1);
				}
			}
			else
			{
				if (j == x_max - 1)
				{
					indices.push_back(index);
					indices.push_back(index + x_max);
					indices.push_back(i*x_max);

					indices.push_back(i*x_max);
					indices.push_back(x_max + index);
					indices.push_back(index + 1);
				}
				else
				{


					indices.push_back(index);
					indices.push_back(index + x_max);
					indices.push_back(index + 1);


					indices.push_back(index + 1);
					indices.push_back(index + x_max);
					indices.push_back(index + x_max + 1);
				}
			}
			
		}

	}
	

}

void Torus::SetDrawingData()
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

	
	/*glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(vertices.size() + normal.size()), nullptr, GL_DYNAMIC_DRAW);


	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*(vertices.size()), &vertices[0]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)*(vertices.size()), sizeof(float)*(normal.size()), &normal[0]);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*(indices.size()), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(sizeof(float) * vertices.size()));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);*/
}

void Torus::SetNormal()
{
	/*for (int i = 0; i < vertices.size() - 5; )
	{
		Vector3 vertex(vertices[i], vertices[i + 1], vertices[i + 2]);
		Vector3 normalValue = (transform.position - vertex).Normalization();
		normal.push_back(normalValue.x);
		normal.push_back(normalValue.y);
		normal.push_back(normalValue.z);
		i += 3;
	}*/
}
