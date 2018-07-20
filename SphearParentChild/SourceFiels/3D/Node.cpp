#include "..\..\Includes\3D\Node.h"

Node::Node(const Vector3 & position, const Vector3 & rotation, const Vector3 & scale, Node* a_parent):
	transform(position, rotation, scale),
	parent(a_parent)
{
	SetWorldMatrix();
}

Node::Node(const Vector3 & position, const Vector3 & rotation, Node* a_parent):
	transform(position, rotation),
	parent(a_parent)
{
	SetWorldMatrix();
}

Node::Node(const Vector3 & position, Node* a_parent):
	transform(position),
	parent(a_parent)
{
	SetWorldMatrix();
}

Node::Node(Node* a_parent):
	transform(),
	parent(a_parent)
{
	SetWorldMatrix();
}

void Node::SetWorldMatrix()
{
	if(parent==nullptr)
	{
		worldMatrix=transform.modelMatrix;
	}
	else
	{
		worldMatrix=transform.modelMatrix*parent->worldMatrix;
	}
}
