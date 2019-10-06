#pragma once
#include <vector>

namespace MathS
{
	//Forward Decleration
	class Vec4;

	class Vec3
	{
	public:
		float x, y, z;

		//Constructors
		Vec3();
		Vec3(float val);
		Vec3(float _x, float _y, float _z);
		Vec3(const Vec3& copy);

		//Operator overrides
		Vec3 operator +(const Vec3& vector);
		Vec3 operator -(const Vec3& vector);
		Vec3 operator =(const Vec3& vector);

		//Methods
		float Dot(const Vec3& vector);
		float Length();
		float Norm();
		Vec3 Normalize();
		Vec3 ScalarMult(float scaler);
		Vec3 Reflect(Vec3& NormVector);
		Vec3 Cross(const Vec3& vector);
		Vec4 Convert4();
	};

	class Vec4
	{
	public:
		float x, y, z, w;

		//Constructors
		Vec4();
		Vec4(float val);
		Vec4(float _x, float _y, float _z, float _w);
		Vec4(const Vec4& copy);

		//Operator overrides
		Vec4 operator +(const Vec4& vector);
		Vec4 operator -(const Vec4& vector);
		Vec4 operator =(const Vec4& vector);

		//Methods
		float Dot(const Vec4& vector);
		float Length();
		float Norm();
		Vec4 Normalize();
		Vec4 ScalarMult(float scaler);
		Vec3 Convert3();
	};

	class Mat3
	{
	private:
		void Fill(float fill);

	public:
		float values[3][3];

		//Constructors
		Mat3();
		Mat3(const Mat3& matrix);
		Mat3(std::vector<float>& vector);

		//Operator overrides
		Mat3 operator +(const Mat3& matrix);
		Mat3 operator -(const Mat3& matrix);
		Mat3 operator *(float number);

		//Methods
		Mat3 Identity();
		Mat3 Zero();
		Mat3 Transpose();
		float Determinant();
	};


	class Mat4
	{
	private:
		void Fill(float fill);

	public:
		float values[4][4];

		//Constructors
		Mat4();
		Mat4(const Mat4& matrix);
		Mat4(std::vector<float>& vector);

		//Operator overrides
		Mat4 operator +(const Mat4& matrix);
		Mat4 operator -(const Mat4& matrix);
		//Multipy by Scalar
		Mat4 operator *(float number);
		//Multiply By Vec3
		Mat4 operator *(const Vec3& vector);
		//Multiply By Vec4
		Mat4 operator *(const Vec4& vector);
		//Multiply 4x4 By 4x4
		Mat4 operator *(const Mat4& matrix);

		//Methods
		Mat4 Scale(Vec3 vector);
		Mat4 Scale(Vec4 vector);
		Mat4 RotateX(float degree);
		Mat4 RotateY(float degree);
		Mat4 RotateZ(float degree);
		Mat4 Transform(Vec4& vector);
		Mat4 Identity();
		Mat4 Zero();
		Mat4 Transpose();
		float Determinant();
	
	};

}