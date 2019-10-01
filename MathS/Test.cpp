#include  "MathS.h"
#include <iostream>

using namespace std;
using namespace MathS;

int main(int argc, const char* argv[])
{
#pragma region Vec3 Tests

	Vec3 vector1(1, 1, 1);
	Vec3 vector2(2, 2, 2);
	Vec3 vector3 = vector1 + vector2;
	cout << "===============================================================================================================\n";
	cout << "Vector 3 Tests\n";
	cout << "===============================================================================================================\n";
	cout << "Test for + override \n";
	cout << "Expected: 333 \n";
	cout << "Actual: " << vector3.x << vector3.y << vector3.z;

	vector3 = vector1 - vector2;
	cout << "\n=================================================\n";
	cout << "Test for - override \n";
	cout << "Expected: -1-1-1 \n";
	cout << "Actual: " << vector3.x << vector3.y << vector3.z;

	vector1 = vector2;
	cout << "\n=================================================\n";
	cout << "Test for = override \n";
	cout << "Expected: 222 \n";
	cout << "Actual: " << vector1.x << vector1.y << vector1.z;

	cout << "\n=================================================\n";
	cout << "Test for Dot Product\n";
	cout << "Expected: 12 \n";
	cout << "Actual: " << vector1.Dot(vector2);;

	cout << "\n=================================================\n";
	cout << "Test for Length\n";
	cout << "Expected: 3.4641 \n";
	cout << "Actual: " << vector1.Length();

	Vec3 vector4 = vector1.Normalize();
	cout << "\n=================================================\n";
	cout << "Test for Normalize\n";
	cout << "Expected: 1 \n";
	cout << "Actual: " << vector4.Length();

	vector4 = vector4.Normalize();
	cout << "\n=================================================\n";
	cout << "Test for Normalize if length is 1 \n";
	cout << "Expected: 1 \n";
	cout << "Actual: " << vector4.Length();


	Vec3 vector5(1, 1, 1);
	vector5 = vector5.ScalarMult(4);
	cout << "\n=================================================\n";
	cout << "Test for Scale \n";
	cout << "Expected: 444 \n";
	cout << "Actual: " << vector5.x << vector5.y << vector5.z;


	Vec3 vector6(1, 1, 1);
	Vec3 vector7(1, 2, 1);
	vector6 = vector6.Cross(vector7);
	cout << "\n=================================================\n";
	cout << "Test for Cross \n";
	cout << "Expected: -101 \n";
	cout << "Actual: " << vector6.x << vector6.y << vector6.z;


	Vec3 vector8(-3, 3, 0);
	Vec3 vector9(3, 0, 0);

	vector8 = vector8.Reflect(vector9);
	cout << "\n=================================================\n";
	cout << "Test for Reflection \n";
	cout << "Expected: 330 \n";
	cout << "Actual: " << vector8.x << vector8.y << vector8.z;
	cout << "\n===============================================================================================================\n";
#pragma endregion Vec3 Tests

#pragma region Vec3 Tests
	Vec4 vector10(1, 1, 1, 1);
	Vec4 vector11(2, 2, 2, 2);
	Vec4 vector12 = vector10 + vector11;
	cout << "Vector 4 Tests\n";
	cout << "===============================================================================================================\n";
	cout << "Test for + override \n";
	cout << "Expected: 3333 \n";
	cout << "Actual: " << vector12.x << vector12.y << vector12.z << vector12.w;

	vector12 = vector10 - vector11;
	cout << "\n=================================================\n";
	cout << "Test for - override \n";
	cout << "Expected: -1-1-1-1 \n";
	cout << "Actual: " << vector12.x << vector12.y << vector12.z << vector12.w;

	vector10 = vector11;
	cout << "\n=================================================\n";
	cout << "Test for = override \n";
	cout << "Expected: 2222 \n";
	cout << "Actual: " << vector10.x << vector10.y << vector10.z << vector10.w;

	cout << "\n=================================================\n";
	cout << "Test for Dot Product\n";
	cout << "Expected: 16 \n";
	cout << "Actual: " << vector10.Dot(vector11);;

	cout << "\n=================================================\n";
	cout << "Test for Length\n";
	cout << "Expected: 4 \n";
	cout << "Actual: " << vector10.Length();

	Vec4 vector13 = vector10.Normalize();
	cout << "\n=================================================\n";
	cout << "Test for Normalize\n";
	cout << "Expected: 1 \n";
	cout << "Actual: " << vector13.Length();

	vector13 = vector13.Normalize();
	cout << "\n=================================================\n";
	cout << "Test for Normalize if length is 1 \n";
	cout << "Expected: 1 \n";
	cout << "Actual: " << vector13.Length();


	Vec4 vector14(1, 1, 1, 1);
	vector14 = vector14.ScalarMult(4);
	cout << "\n=================================================\n";
	cout << "Test for Scale \n";
	cout << "Expected: 4444 \n";
	cout << "Actual: " << vector14.x << vector14.y << vector14.z << vector14.w;
	cout << "\n===============================================================================================================\n";
#pragma endregion Vec4 Tests
}