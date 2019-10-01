#pragma once

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
}