#include "..\..\Includes\Shapes\Grid.h"


Grid::Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath, const Vector3 & a_position, const Vector3 & a_rotation, const Vector3 & a_scale, Node* a_parent):
	Object(vertexPath, fragmentPath,a_position,a_rotation,a_scale,a_parent),
	gridSize(a_gridSize),
	position(a_position)
{
	SetVertices();
	SetDrawingData();
}

Grid::Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath, const Vector3 & a_position, const Vector3 & a_rotation, Node* a_parent):
	Object(vertexPath, fragmentPath, a_position, a_rotation,a_parent),
	gridSize(a_gridSize),
	position(a_position)

{
	SetVertices();
	SetDrawingData();
}

Grid::Grid(float a_gridSize, const char * vertexPath, const char * fragmentPath, const Vector3 & a_position, Node* a_parent):
	Object(vertexPath, fragmentPath,a_parent),
	gridSize(a_gridSize),
	position(a_position)
{
	
	SetVertices();
	SetDrawingData();
}

//void Grid::SetVertices(Vector3 position, float a_gridSize)
void Grid::SetVertices()
{
	int noOfVerticesIn_X=cellCount+1;
	int noOfVerticesIn_Y = cellCount + 1;
	float cellSize = gridSize / cellCount;

	int index=0;
	
	for (int j = 0; j < noOfVerticesIn_Y; j++)
	{
		for (int x = 0; x < noOfVerticesIn_X; x++)
		{
			//vertices
			float x_pos= position.x+x*cellSize;
			float y_pos=position.y+j*cellSize;
			vertices.push_back(x_pos);
			vertices.push_back(y_pos);
			vertices.push_back(position.z);
			
			//second tringle
			if(j<cellCount && x<cellCount)
			{
				index = j * noOfVerticesIn_X + x;
				indices.push_back(index);
				indices.push_back(index + noOfVerticesIn_X);
				indices.push_back(index + 1);
				
					
					indices.push_back(index+1);
					indices.push_back(index + noOfVerticesIn_X );
					indices.push_back(index+noOfVerticesIn_X+1);
				
			
			}
		}
			std::cout<<"dfdf";

	}

	
}

void Grid::SetDrawingData()
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

void Grid::Render(const Camera& camera)
{
	Object::Render(camera);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
