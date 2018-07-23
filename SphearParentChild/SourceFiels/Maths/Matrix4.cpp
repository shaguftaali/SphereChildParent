#include "..\..\Includes\Maths\Matrix4.h"
#include <cassert>

//i=row
//j= column

const Matrix4 Matrix4::IdentityMat = Matrix4(
	Vector4(1, 0, 0, 0),
	Vector4(0, 1, 0, 0),
	Vector4(0, 0, 1, 0),
	Vector4(0, 0, 0, 1)
);

Matrix4::Matrix4()
{
	
	setMatrixRow(0, Vector4());
	setMatrixRow(1, Vector4());
	setMatrixRow(2, Vector4());
	setMatrixRow(3, Vector4());
}

Matrix4::Matrix4(const float arg[4][4])
{
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			mat[i][j] = arg[i][j];
		}
	}
}

Matrix4::Matrix4(const Vector4 & v1, const Vector4 & v2, const Vector4 & v3, const Vector4 & v4)
{
	setMatrixRow(0, v1);
	setMatrixRow(1, v2);
	setMatrixRow(2, v3);
	setMatrixRow(3, v4);

}

Matrix4 Matrix4::Transpose()
{
	Matrix4 mat4;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat4[j][i]=mat[i][j];
		}

	}
	return mat4;
}

float * Matrix4::operator[](int index)
{
	assert(index >= 0 && index<4 && "index out of bound");
	return mat[index];
}

const float * Matrix4::operator[](int index) const
{
	return mat[index];
}

Matrix4 operator+(const Matrix4 & mat1, const Matrix4 & mat2)
{
	Matrix4 mat4;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			mat4[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return mat4;
}

Matrix4 operator-(const Matrix4 & mat1, const Matrix4 & mat2)
{
	Matrix4 mat4;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			mat4[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
	return mat4;
}

Matrix4 operator*(const Matrix4 & mat1, const Matrix4 & mat2)
{
	Matrix4 mat4;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			for (int k = 0; k<4; k++)
			{
				mat4[i][j] += mat1[i][k] * mat2[k][j];

			}
		}
	}
	return mat4;
}

Vector4 operator*(const Matrix4 & mat1, const Vector4 & B)
{
	Vector4 vec4;
	int index = 0;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			vec4.arr[i] += mat1[i][j] * B.arr[j];
		}
	}
	vec4.x=vec4.arr[0];
	vec4.y = vec4.arr[1];
	vec4.z = vec4.arr[2];
	vec4.w = vec4.arr[3];

	return vec4;
}

Matrix4 operator*(const float scaler, const Matrix4 & mat2)
{
	Matrix4 mat4;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			mat4[i][j] = scaler * mat2[i][j];
		}
	}
	return mat4;
}

Matrix4 operator/(const float scaler, const Matrix4 & mat2)
{
	assert(scaler != 0);
	Matrix4 mat4;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			mat4[i][j] = mat2[i][j] / scaler;
		}
	}
	return mat4;
}

void Matrix4::setMatrixRow(int row, const Vector4& vec4)
{


	mat[row][0] = vec4.x;
	mat[row][1] = vec4.y;
	mat[row][2] = vec4.z;
	mat[row][3] = vec4.w;
}