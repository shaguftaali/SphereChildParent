#pragma once
#include "Vector4.h"

class Matrix4
{

	public:
		Matrix4();
		Matrix4(const float arg[4][4]);
		Matrix4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4 );

	Matrix4 Transpose();

	friend Matrix4 operator +(const Matrix4& mat1, const Matrix4& mat2);
	friend Matrix4 operator -(const Matrix4& mat1, const Matrix4& mat2);
	friend Matrix4 operator *(const Matrix4& mat1, const Matrix4& mat2);
	friend Vector4 operator *(const Matrix4& mat1, const Vector4& vector4);
	friend Matrix4 operator *(const float scaler, const Matrix4& mat2);
	friend Matrix4 operator /(const float scaler, const Matrix4& mat2);
	float* operator [](int index);
	const float* operator[](int index) const;
	static  const Matrix4 IdentityMat;
	private:
		float mat[4][4];
		void setMatrixRow(int row, const Vector4& vec4);
};

