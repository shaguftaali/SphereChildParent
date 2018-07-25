#pragma once
class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float m_x,float m_y,float m_z);
	//friend  Vector3 operator + (const Vector3& v1, const Vector3& v2);
	Vector3 operator + (const Vector3& vec);
	friend  Vector3 operator - (const Vector3& v1, const Vector3& v2);
	//Vector3 operator - (const Vector3& vec) const;
	friend  Vector3 operator * (const float scaler, const Vector3& vec3);
	 Vector3 operator * (const float scaler);
	 Vector3 operator / (const float scaler);
	friend  Vector3 operator / (const Vector3 & vec3, const float scaler);
	static  Vector3 CrossProduct (const Vector3& v1, const Vector3& v2);
	static  float DotProduct (const Vector3& v1, const Vector3& v2);
	static  float Distance(const Vector3& v1, const Vector3& v2);
	Vector3 Normalization();
	static  float Magnitude(const Vector3& vec3);
	static  float SqrMagnitude(const Vector3& vec3);
	float Magnitude() const;
	float SqrMagnitude() const;
};