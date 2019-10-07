#include "MathS.h"
#include <math.h>

#define PI 3.14159f

//====================================
//	Vector3 Shit
//====================================

#pragma region Constructors
//Default Constructor
MathS::Vec3::Vec3()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}
//Set all to same value
MathS::Vec3::Vec3(float val)
{
	x = val;
	y = val;
	z = val;
}
//Set all values seperatly
MathS::Vec3::Vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
//Copy Constructor
MathS::Vec3::Vec3(const Vec3& copy)
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
}
#pragma endregion Constructors

#pragma region Operator Overloads
MathS::Vec3 MathS::Vec3::operator +(const Vec3& vector)
{
	return Vec3(x + vector.x, y + vector.y, z + vector.z);
}

MathS::Vec3 MathS::Vec3::operator -(const Vec3& vector)
{
	return Vec3(x - vector.x, y - vector.y, z - vector.z);
}

MathS::Vec3 MathS::Vec3::operator =(const Vec3& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}
#pragma endregion Operator Overloads

#pragma region Methods
float MathS::Vec3::Dot(const Vec3& vector)
{
	return x * vector.x + y * vector.y + z * vector.z;
}

float MathS::Vec3::Length()
{
	return sqrt(x * x + y * y + z * z);
}

float  MathS::Vec3::Norm()
{
	return Length();
}

MathS::Vec3  MathS::Vec3::Normalize()
{
	return Vec3(x / Length(), y / Length(), z / Length());
}

MathS::Vec3  MathS::Vec3::ScalarMult(float scaler)
{
	return Vec3(x * scaler, y * scaler, z * scaler);
}

MathS::Vec3  MathS::Vec3::Reflect(Vec3& NormVector)
{
	NormVector = NormVector.Normalize();
	return *this - NormVector.ScalarMult(2 * this->Dot(NormVector));
}

MathS::Vec3  MathS::Vec3::Cross(const Vec3& vector)
{
	float _x = y * vector.z - z * vector.y;
	float _y = z * vector.x - x * vector.z;
	float _z = x * vector.y - y * vector.x;
	return Vec3(_x, _y, _z);

}

MathS::Vec4 MathS::Vec3::Convert4()
{
	return Vec4(x, y, z, 1);
}
#pragma endregion Methods

//====================================
//	Vector4 Shit
//====================================

#pragma region Constructors
//Default Constructor
MathS::Vec4::Vec4()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
};
//Set all to same value
MathS::Vec4::Vec4(float val)
{
	x = val;
	y = val;
	z = val;
	w = val;
}
//Set all values seperatly
MathS::Vec4::Vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}
//Copy Constructor
MathS::Vec4::Vec4(const Vec4& copy)
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
	w = copy.w;
}
#pragma endregion Constructors

#pragma region Operator Overloads
MathS::Vec4 MathS::Vec4::operator +(const Vec4& vector)
{
	return Vec4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}

MathS::Vec4 MathS::Vec4::operator -(const Vec4& vector)
{
	return Vec4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

MathS::Vec4 MathS::Vec4::operator =(const Vec4& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;
	return *this;
}
#pragma endregion Operator Overloads

#pragma region Methods
float MathS::Vec4::Dot(const Vec4& vector)
{
	return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
}

float MathS::Vec4::Length()
{
	return sqrt(x * x + y * y + z * z + w * w);
}

float  MathS::Vec4::Norm()
{
	return Length();
}

MathS::Vec4  MathS::Vec4::Normalize()
{
	return Vec4(x / Length(), y / Length(), z / Length(), w / Length());
}

MathS::Vec4  MathS::Vec4::ScalarMult(float scaler)
{
	return Vec4(x * scaler, y * scaler, z * scaler, w * scaler);
}

MathS::Vec3 MathS::Vec4::Convert3()
{
	return Vec3(x, y, z);
}
#pragma endregion Methods

//====================================
//	Matrix3 Shit
//====================================

#pragma region Constructors
//Default Constructor
MathS::Mat3::Mat3()
{
	Fill(1);
}

//Copy Constructor Matrix
MathS::Mat3::Mat3(const Mat3& matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i][j] = matrix.values[i][j];
		}
	}
}

//Copy Constructor Vector
MathS::Mat3::Mat3(std::vector<float>& vector)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i][j] = vector[count];
			++count;
		}
	}
}
#pragma endregion Constructors

#pragma region Operator Overloads
MathS::Mat3 MathS::Mat3::operator+(const Mat3& matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i][j] += matrix.values[i][j];
		}
	}
	return *this;
}

MathS::Mat3 MathS::Mat3::operator-(const Mat3& matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i][j] -= matrix.values[i][j];
		}
	}
	return *this;
}

MathS::Mat3 MathS::Mat3::operator*(float number)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i][j] *= number;
		}
	}
	return *this;
}
#pragma endregion Operator Overloads

#pragma region Methods
void MathS::Mat3::Fill(float fill)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; i < 3; i++)
		{
			values[i][j] = fill;
		}
	}
}

MathS::Mat3 MathS::Mat3::Identity()
{
	Fill(0);
	values[0][0] = 1.0f;
	values[1][1] = 1.0f;
	values[2][2] = 1.0f;
	return *this;
}

MathS::Mat3 MathS::Mat3::Zero()
{
	Fill(0);
	return *this;
}

MathS::Mat3 MathS::Mat3::Transpose()
{
	Mat3 matrix;
	matrix.Fill(0);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix.values[i][j] = values[j][i];
		}
	}
	return matrix;
}

float MathS::Mat3::Determinant()
{
	return values[0][0] * (values[1][1] * values[2][2] - values[2][1] * values[1][2])
		- values[0][1] * (values[1][0] * values[2][2] - values[2][0] * values[1][2])
		+ values[0][2] * (values[1][0] * values[2][1] - values[2][0] * values[1][1]);
}
#pragma endregion Methods

//====================================
//	Matrix4 Shit
//====================================


#pragma region Constructors
//Default Constructor
MathS::Mat4::Mat4()
{
	Fill(1);
}

//Copy Constructor Matrix
MathS::Mat4::Mat4(const Mat4& matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			values[i][j] = matrix.values[i][j];
		}
	}
}

//Copy Constructor Vector
MathS::Mat4::Mat4(std::vector<float>& vector)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			values[i][j] = vector[count];
			++count;
		}
	}
}
#pragma endregion Constructors

#pragma region Operator Overloads
MathS::Mat4 MathS::Mat4::operator+(const Mat4& matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			values[i][j] += matrix.values[i][j];
		}
	}
	return *this;
}

MathS::Mat4 MathS::Mat4::operator-(const Mat4& matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			values[i][j] -= matrix.values[i][j];
		}
	}
	return *this;
}

//Multipy by Scalar
MathS::Mat4 MathS::Mat4::operator*(float number)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			values[i][j] *= number;
		}
	}
	return *this;
}

//Multiply By Vec3
MathS::Mat4 MathS::Mat4::operator*(const Vec3& vector)
{
	values[0][0] *= vector.x;	values[0][1] *= vector.y;	values[0][2] *= vector.z;
	values[1][0] *= vector.x;	values[1][1] *= vector.y;	values[1][2] *= vector.z;
	values[2][0] *= vector.x;	values[2][1] *= vector.y;	values[2][2] *= vector.z;
	values[3][0] *= vector.x;	values[3][1] *= vector.y;	values[3][2] *= vector.z;
	return *this;
}

//Multiply By Vec4
MathS::Mat4 MathS::Mat4::operator*(const Vec4& vector)
{
	values[0][0] *= vector.x;	values[0][1] *= vector.y;	values[0][2] *= vector.z;	values[0][3] *= vector.w;
	values[1][0] *= vector.x;	values[1][1] *= vector.y;	values[1][2] *= vector.z;	values[1][3] *= vector.w;
	values[2][0] *= vector.x;	values[2][1] *= vector.y;	values[2][2] *= vector.z;	values[2][3] *= vector.w;
	values[3][0] *= vector.x;	values[3][1] *= vector.y;	values[3][2] *= vector.z;	values[3][3] *= vector.w;
	return *this;
}

//Multiply 4x4 By 4x4
MathS::Mat4 MathS::Mat4::operator*(const Mat4& matrix)
{
	Mat4 matrix1;
	matrix1.Fill(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				matrix1.values[i][j] += values[i][k] * matrix.values[k][j];
			}
		}
	}
	return matrix1;
}


#pragma endregion Operator Overloads

#pragma region Methods
void MathS::Mat4::Fill(float fill)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; i < 4; i++)
		{
			values[i][j] = fill;
		}
	}
}

MathS::Mat4 MathS::Mat4::Scale(Vec3 vector)
{
	return *this * vector;
}

MathS::Mat4 MathS::Mat4::Scale(Vec4 vector)
{
	return *this * vector;
}

MathS::Mat4 MathS::Mat4::RotateX(float degree)
{
	Mat4 matrix;
	matrix.Fill(0);

	degree = degree * (PI / 180);

	matrix.values[0][0] = 1;
	matrix.values[1][1] = cosf(degree);		matrix.values[1][2] = -sin(degree);
	matrix.values[2][1] = sinf(degree);		matrix.values[2][2] = cosf(degree);
	matrix.values[3][3] = 1;

	return *this * matrix;
}

MathS::Mat4 MathS::Mat4::RotateY(float degree)
{
	Mat4 matrix;
	matrix.Fill(0);

	degree = degree * (PI / 180);

	matrix.values[1][1] = 1;
	matrix.values[0][0] = cosf(degree);		matrix.values[0][2] = sin(degree);
	matrix.values[2][0] = -sinf(degree);	matrix.values[2][2] = cosf(degree);
	matrix.values[3][3] = 1;

	return *this * matrix;
}

MathS::Mat4 MathS::Mat4::RotateZ(float degree)
{
	Mat4 matrix;
	matrix.Fill(0);

	degree = degree * (PI / 180);

	matrix.values[2][2] = 1;
	matrix.values[0][0] = cosf(degree);		matrix.values[0][1] = -sin(degree);
	matrix.values[1][0] = sinf(degree);		matrix.values[1][1] = cosf(degree);
	matrix.values[3][3] = 1;

	return *this * matrix;
}

MathS::Mat4 MathS::Mat4::Transform(Vec4& vector)
{
	Mat4 matrix;
	matrix.Fill(0);

	matrix.values[0][0] = 1;
	matrix.values[1][1] = 1;
	matrix.values[2][2] = 1;
	matrix.values[3][0] = vector.x;
	matrix.values[3][1] = vector.y;
	matrix.values[3][2] = vector.z;
	matrix.values[3][3] = vector.w;

	return matrix;
}

MathS::Mat4 MathS::Mat4::Identity()
{
	Mat4 matrix;
	matrix.Fill(0);

	matrix.values[0][0] = 1;
	matrix.values[1][1] = 1;
	matrix.values[2][2] = 1;
	matrix.values[3][3] = 1;
	return matrix;
}

MathS::Mat4 MathS::Mat4::Zero()
{
	Fill(0.0f);
	return *this;
}

MathS::Mat4 MathS::Mat4::Transpose()
{
	Mat4 matrix;
	matrix.Fill(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix.values[i][j] = values[j][i];
		}
	}
	return matrix;
}

float MathS::Mat4::Determinant()
{
}

#pragma endregion Methods