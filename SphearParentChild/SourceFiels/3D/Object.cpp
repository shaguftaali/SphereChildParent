 #include "../../Includes/3D/Object.h"


Object::Object(const char * vertexPath, const char * fragmentPath, Node* a_parent):
	shader(vertexPath,fragmentPath),
	Node(a_parent)
{
}

Object::Object(const char * vertexPath, const char * fragmentPath, const Vector3 & position, const Vector3 & rotation, const Vector3 & scale, Node* a_parent):
shader(vertexPath,fragmentPath),
Node(position,rotation,scale,a_parent)
{
	
}

Object::Object(const char * vertexPath, const char * fragmentPath, const Vector3 & position, const Vector3 & rotation, Node* a_parent):
	shader(vertexPath, fragmentPath),
	Node(position, rotation,a_parent)
{}

Object::Object(const char * vertexPath, const char * fragmentPath, const Vector3 & position, Node* a_parent):
	shader(vertexPath, fragmentPath),
	Node(position,a_parent)
{
	
}

void Object::Render(const Camera& camera)
{
	shader.use();
		transform.SetWorldMatrix(parent);
	if(parent==nullptr)
	{
		shader.setMat4("model", transform.modelMatrix);
	}
	else
	{
		shader.setMat4("model", transform.worldMatrix);
	}
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
