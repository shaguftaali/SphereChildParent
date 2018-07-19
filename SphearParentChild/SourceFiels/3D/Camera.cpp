#include "..\..\Includes\3D\Camera.h"
#include <math.h>

#define PI 3.14159

Camera::Camera(const Vector3 & a_position, const Vector3 & target, const float a_far, const float a_near, const float a_FOV):
position(a_position),
far(a_far),
near(a_near),
FOV(a_FOV)
{
	eyeDirection=(target-position).Normalization();
	SetViewMatrix();
	SetProjectionMatrix();
}

void Camera::SetViewMatrix()
{
	Vector3 xAxis=Vector3::CrossProduct(eyeDirection,Vector3(0,1,0));
	xAxis=xAxis.Normalization();

	Vector3 yAxis=Vector3::CrossProduct(eyeDirection,xAxis);
	yAxis=yAxis.Normalization();

	float ex = -Vector3::DotProduct(xAxis, position);
	float ey = -Vector3::DotProduct(yAxis, position);
	float ez = Vector3::DotProduct(eyeDirection, position);

	viewMatrix = Matrix4(
		Vector4(xAxis.x, xAxis.y, xAxis.z, 0),
		Vector4(yAxis.x, yAxis.y, yAxis.z, 0),
		Vector4(-eyeDirection.x, -eyeDirection.y, -eyeDirection.z, 0),
		Vector4(ex, ey, ez, 1)
	);
}

void Camera::SetProjectionMatrix()
{
	const float radians = (float)FOV*(PI / 180);
	float A = -(far + near) / (far - near);
	float B = (-2 * far*near) / (far - near);
	projectionMatrix = Matrix4(
		Vector4(1 / tanf(radians / 2), 0, 0, 0),
		Vector4(0, 1 / tanf(radians / 2), 0, 0),
		Vector4(0, 0, A, -1),
		Vector4(0, 0, B, 0)
	);

}
