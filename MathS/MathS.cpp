#include "MathS.h"
#include "Math.h"

//====================================
//	Vector3 Shit
//====================================
#pragma region Vector3

#pragma region Constructors
//Default Constructor
MathS::Vec3::Vec3()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
};
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
	return x* vector.x + y * vector.y + z * vector.z;
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
	return *this - NormVector.ScalarMult(2 *this ->Dot(NormVector));
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

#pragma endregion Vector3

//====================================
//	Vector4 Shit
//====================================
#pragma region Vector4

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

#pragma endregion Vector4

//====================================
//	Matrix Shit
//====================================