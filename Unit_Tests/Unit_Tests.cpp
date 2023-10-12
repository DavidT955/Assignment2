#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(Perimeter_Test)
		{
			int length = 3, width = 3;
			int perimeter = length + length + width;
			getPerimeter(&length, &width);
			Assert::AreEqual(9, perimeter);
		}
		TEST_METHOD(Area_test)
		{
			int length = 3, width = 3;
			int area = length * width;
			getArea(&length, &width);
			Assert::AreEqual(9, area);
		}
		TEST_METHOD(Valid_Length_test)
		{
			int length;
			int input = 6;
			setLength( input, &length);
			Assert::AreEqual(6, length);
		}
		TEST_METHOD(Negative_Length_test)
		{
			int length = -99;
			int input = -1;
			setLength(input, &length);
			Assert::AreEqual(-99, length);
		}
		TEST_METHOD(Decimal_Length_test)
		{
			int length;
			int input = 2.2;
			setLength(input, &length); 
			Assert::AreEqual(2, length);
		}
		TEST_METHOD(Valid_Width_Test)
		{
			int width;
			int input = 20;
			setWidth(input, &width);
			Assert::AreEqual(20, width);
		}
		TEST_METHOD(Negative_Width_Test)
		{
			int width = -99; 
			int input = -2;
			setWidth(input, &width);
			Assert::AreEqual(-99, width);
		}
		TEST_METHOD(Decimal_Width_Test)
		{
			int width;
			int input = 3.4;
			setWidth(input, &width);
			Assert::AreEqual(3, width);
		}

	};
}
