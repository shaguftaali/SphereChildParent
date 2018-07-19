 #include "../../Includes/3D/Object.h"


Object::Object(const char * vertexPath, const char * fragmentPath):
	shader(vertexPath,fragmentPath)
{
}

Object::Object(const char * vertexPath, const char * fragmentPath, const Vector3 & position, const Vector3 & rotation, const Vector3 & scale):
shader(vertexPath,fragmentPath),
transform(position,rotation,scale)
{
	
}

Object::Object(const char * vertexPath, const char * fragmentPath, const Vector3 & position, const Vector3 & rotation):
	shader(vertexPath, fragmentPath),
	transform(position, rotation)
{}

Object::Object(const char * vertexPath, const char * fragmentPath, const Vector3 & position):
	shader(vertexPath, fragmentPath),
	transform(position)
{
	
}

void Object::Render(const Camera& camera)
{
	shader.use();
	shader.setMat4("model", transform.modelMatrix);
	shader.setMat4("view", camera.viewMatrix);
	shader.setMat4("projection", camera.projectionMatrix);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glDrawArrays(GL_TRIANGLES,0,3);
	
}

void Object::DeleteDrawingData()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Object::SetIndices()
{}

void Object::SetNormal()
{}
