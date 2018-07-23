#pragma once
#include "../../Includes/Maths/Vector3.h"
#include "../../Includes/Maths/Matrix4.h"
//#include "../3D/Node.h"

class  Node;

enum Axis
{
	X,
	Y,
	Z
};
class  Transform
{
public:
	Transform();
	Transform(Node* a_parent);
	Transform(const Vector3& a_position, Node* a_parent);
	Transform(const Vector3& a_position, const Vector3& a_rotation, Node* a_parent);
	Transform(const Vector3& a_position,const Vector3& a_rotation,const Vector3& a_scale, Node* a_parent);
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void Position(Vector3 pos);
	Vector3 Position() const;
	Node* parent;

	void Rotate(Vector3 axis,float angle);
	void Translate(Vector3 targetPos);

	Matrix4 modelMatrix;
	void SetModelMatrix();

	Matrix4 worldMatrix;
	void SetWorldMatrix(Node* parent);
private:

};
