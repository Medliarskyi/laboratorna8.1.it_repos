#include "pch.h"
#include "CppUnitTest.h"
#include "../lab81it/lab81it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
	TEST_CLASS(UnitTest81it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char input1[] = "This is a while loop.";
			replaceWhileWithStars(input1);
			Assert::AreEqual("This is a ** loop.", input1, L"Failed: Replacement of 'while' with '**' didn't work as expected");

			char input2[] = "whilewhile";
			replaceWhileWithStars(input2);
			Assert::AreEqual("****", input2, L"Failed: Replacement of consecutive 'while' occurrences didn't work as expected");

			char input4[] = "";
			replaceWhileWithStars(input4);
			Assert::AreEqual("", input4, L"Failed: Empty string should remain unchanged");
		}
	};
}
