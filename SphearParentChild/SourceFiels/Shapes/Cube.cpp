#include "..\..\Includes\Shapes\Cube.h"

Cube::Cube(const char * vertexPath, const char * fragmentPath, Vector3 position, float a_size, Node * a_parent):
	Object(vertexPath, fragmentPath, position, a_parent),
	size(a_size)
{
	SetVertices();
	SetIndices();
	SetNormal();
	SetDrawingData();
}

void Cube::Render(const Camera & camera)
{
	Object::Render(camera);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	shader.setVec3("lightPos", 0.0f, 0.0f, 50.0f);
	shader.setVec3("objectColor", 0.5f, 0.2f, 0.51f);
	shader.setVec3("lightColor", 1.0f, 0.5f, 1.0f);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Cube::SetVertices()
{
	float verticesArray[] = {
		// front
		-0.2, -0.2, -0.2,  	   //(0)
		 0.2, -0.2, -0.2,  	   //(1)
		 0.2,  0.2, -0.2,  	   //(2)
		-0.2,  0.2, -0.2,  	   //(3)


		 //back									   
		 -0.2,  -0.2,  0.2 ,   //(4)
		  0.2,  -0.2,  0.2 ,   //(5)
		  0.2,   0.2,  0.2 ,   //(6)
		 -0.2,   0.2,  0.2,    //(7)

		 //left									   
		 -0.2, -0.2, -0.2,    //(8)
		 -0.2,  -0.2, 0.2,    //(9)
		 -0.2,   0.2, 0.2,	  //(10)
		 -0.2,  0.2, -0.2,	  //(11)

		 //right								   
		 0.2,  -0.2, -0.2,   //(12)
		 0.2,   0.2, -0.2,   //(13)
		 0.2,   0.2,  0.2,   //(14)
		 0.2,  -0.2,  0.2,   //(15)

		 //top				
		 -0.2,  0.2, -0.2,   //(16)
		  0.2,  0.2, -0.2,   //(17)
		  0.2,  0.2,  0.2,   //(18)
		 -0.2,  0.2,  0.2,   //(19)

		// bottom
		 -0.2, -0.2, -0.2,   //(20)
		 -0.2, -0.2,  0.2,   //(21)
		  0.2, -0.2,  0.2,   //(22)
		  0.2, -0.2, -0.2,   //(23)
	};

	for (int i=0;i<sizeof(verticesArray);i++)
	{
		vertices.push_back(verticesArray[i]);
	}

}

void Cube::SetIndices()
{
	unsigned int indicesArray[] = {
		//front
		0,1,2,
		0,2,3,

		//right face
		12,14,13,
		12,15,14,

		//bottom face
		20,21,22,
		20,22,23,

		//top face
		16,17,18,
		16,18,19,

		//left face

		8,10,9,
		8,11,10,

		//back face
		4,6,5,
		4,7,6

	};

	for (int i = 0; i<sizeof(indicesArray); i++)
	{
		indices.push_back(indicesArray[i]);
	}
}

void Cube::SetDrawingData()
{
	
	glGenVertexArrays(1, &VAO);
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

	glBindVertexArray(0);
}

void Cube::SetNormal()
{
	float normalArray[] = {
		// front
		 0.0, 0.0, 1.0f,		   //(0)
		 0.0, 0.0, 1.0f,		   //(1)
		 0.0, 0.0, 1.0f,		   //(2)
		 0.0, 0.0, 1.0f,		   //(3)


		 //back									   
		0.0, 0.0, -1.0f,	   //(4)
		0.0, 0.0, -1.0f,	   //(5)
		0.0, 0.0, -1.0f,	   //(6)
		0.0, 0.0, -1.0f,	   //(7)

		 //left									   
		1.0, 0.0, 0.0f,	       //(8)
		1.0, 0.0, 0.0f,	       //(9)
		1.0, 0.0, 0.0f,		   //(10)
		1.0, 0.0, 0.0f,		   //(11)

		  //right								   
		 -1.0, 0.0, 0.0f,	   //(12)
		 -1.0, 0.0, 0.0f,	   //(13)
		 -1.0, 0.0, 0.0f,	   //(14)
		 -1.0, 0.0, 0.0f,	   //(15)

		//top								   
		  0.0, 1.0, 0.0f,		//(16)
		  0.0, 1.0, 0.0f,		//(17)
		  0.0, 1.0, 0.0f,		//(18)
		  0.0, 1.0, 0.0f,		//(19)

		 // bottom
		 0.0,-1.0, 0.0f,        //(20)
		 0.0,-1.0, 0.0f,        //(21)
		 0.0,-1.0, 0.0f,        //(22)
		 0.0,-1.0, 0.0f,        //(23)
	};

	for (int i = 0; i<sizeof(normalArray); i++)
	{
		normal.push_back(normalArray[i]);
	}
}
