#include "..\..\Includes\Maths\Transform.h"
#include <math.h>

#define PI 3.14159

Transform::Transform():
position(Vector3()),
rotation(Vector3()),
scale(Vector3(1,1,1))
{
	SetModelMatrix();
}

Transform::Transform(const Vector3& a_position):
	position(a_position),
	rotation(Vector3()),
	scale(Vector3(1, 1, 1))
{
	SetModelMatrix();
}

Transform::Transform(const Vector3& a_position, const Vector3& a_rotation):
	position(a_position),
	rotation(a_rotation),
	scale(Vector3(1, 1, 1))
{
	SetModelMatrix();
}

Transform::Transform(const Vector3& a_position, const Vector3& a_rotation, const Vector3& a_scale):
	position(a_position),
	rotation(a_rotation),
	scale(a_scale)
{
	SetModelMatrix();
}

void Transform::Rotate(Vector3 axis, float angle)
{
	const float radian=angle*(PI/180.0f);
	float A00=cos(radian)+axis.x*axis.x*(1-cos(radian));
	float A01=axis.y*axis.z*(1-cos(radian))+axis.z;
	float A02=axis.z*axis.x*(1-cos(radian))-axis.y*sin(radian);
	float A03=0;

	float A10 = axis.x*axis.y*(1 - cos(radian)) - axis.z*sin(radian);
	float A11= cos(radian)+axis.y*axis.y*(1-cos(radian));
	float A12= axis.z*axis.y*(1 - cos(radian)) + axis.x*sin(radian);
	float A13=0;

	float A20= axis.x*axis.z*(1 - cos(radian)) + axis.y*sin(radian);
	float A21 = axis.y*axis.z*(1 - cos(radian)) - axis.x*sin(radian);
	float A22 = cos(radian) + axis.z*axis.z*(1 - cos(radian));
	float A23=0;


	//float A00 = cos(radian) + (position.x+axis.x)*(position.x+axis.x)*(1 - cos(radian));
	//float A01 = (position.y+axis.y)*(position.z+axis.z)*(1 - cos(radian)) + (position.z + axis.z);
	//float A02 = (position.z+axis.z)*(position.x + axis.x)*(1 - cos(radian)) - (position.y + axis.y)*sin(radian);
	//float A03 = 0;

	//float A10 = (position.x + axis.x)*(position.y + axis.y)*(1 - cos(radian)) - (position.z + axis.z)*sin(radian);
	//float A11 = cos(radian) + (position.y + axis.y)*(position.y + axis.y)*(1 - cos(radian));
	//float A12 = (position.z + axis.z)*(position.y + axis.y)*(1 - cos(radian)) + (position.x + axis.x)*sin(radian);
	//float A13 = 0;

	//float A20 = (position.x + axis.x)*(position.z + axis.z)*(1 - cos(radian)) + (position.y + axis.y)*sin(radian);
	//float A21 = (position.y + axis.y)*(position.z + axis.z)*(1 - cos(radian)) - (position.x + axis.x)*sin(radian);
	//float A22 = cos(radian) + (position.z + axis.z)*(position.z + axis.z)*(1 - cos(radian));
	//float A23 = 0;

	Matrix4 axisRotationMat{
			Vector4(A00,A01,A02,A03),
			Vector4(A10,A11,A12,A13),
			Vector4(A20,A21,A22,A23),
			Vector4(  0,  0,  0,  1),
		};

	modelMatrix=modelMatrix*axisRotationMat;
}

void Transform::Translate(Vector3 targetPos)
{
	

	const Matrix4 TranslationMat
	{
		Vector4(1,0,0,targetPos.x),
		Vector4(0,1,0,targetPos.y),
		Vector4(0,0,1,targetPos.z),
		Vector4(0,0,0,1)
	};

	Vector4 target(position,1);

	Vector4 pos=TranslationMat*target;
	position.x=pos.x;
	position.y = pos.y;
	position.z = pos.z;

	SetModelMatrix();
}

void Transform::SetModelMatrix()
{
	Vector3 radian=rotation * (PI /180.0f);
		const Matrix4 TranslationMat
		{
			Vector4(1,0,0,0),
			Vector4(0,1,0,0),
			Vector4(0,0,1,0),
			Vector4(position.x,position.y,position.z,1)
		};

		const Matrix4 ScalMat
		{
			Vector4(scale.x,      0      ,0,0),
			Vector4(	  0,scale.y,      0,0),
			Vector4(	  0,      0,scale.z,0),
			Vector4(	  0,      0,      0,1)
		};

	const Matrix4 X_RotationMat
		{
			Vector4(1,             0,              0, 0),
			Vector4(0,  cos(radian.x), sin(radian.x), 0),
			Vector4(0, -sin(radian.x), cos(radian.x), 0),
			Vector4(0,              0,             0, 1)
		};

	const Matrix4 Y_RotationMat
	{
		Vector4( cos(radian.y), 0, -sin(radian.y), 0),
		Vector4(             0, 1,              0, 0),
		Vector4( sin(radian.y), 0,  cos(radian.x), 0),
		Vector4(             0, 0,              0, 1)
	};

	const Matrix4 Z_RotationMat
	{
		Vector4( cos(radian.z), sin(radian.z), 0, 0),
		Vector4(-sin(radian.z), cos(radian.z), 0, 0),
		Vector4(             0,             0, 1, 0),
		Vector4(             0,			    0, 0, 1)
	};

	/*Matrix4 M1=X_RotationMat*ScalMat;
	Matrix4 M2=Y_RotationMat*M1;
	Matrix4 M3=Z_RotationMat*M2;
	modelMatrix=TranslationMat*M3;*/
	Matrix4 M1 = ScalMat* X_RotationMat ;
	Matrix4 M2 = M1*Y_RotationMat;
	Matrix4 M3 = M2*Z_RotationMat;
	modelMatrix =M3*TranslationMat ;
}


