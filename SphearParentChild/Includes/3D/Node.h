#pragma once
#include "../Maths/Transform.h"
#include <vector>

class Node
{
public:
	Node(const Vector3& position, const Vector3& rotation, const Vector3& scale, Node* a_parent);
	Node(const Vector3& position, const Vector3& rotation, Node* a_parent);
	Node(const Vector3& position, Node* a_parent);
	Node(Node* a_parent);
	Transform transform;
	std::vector<Node*> childs;
	Node* parent;
	Matrix4 worldMatrix;
	void SetWorldMatrix();
};
