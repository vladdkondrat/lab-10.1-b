#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 10.1 b/lab 10.1 b.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1012
{
	TEST_CLASS(UnitTest1012)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<Student> students = {
				{"Ivanov", 1, COMPUTER_SCIENCE, 5, 5, .programmingGrade = 5},
				{"Petrov", 2, INFORMATICS, 4, 5, .numericalMethodsGrade = 4},
				{"Sidorov", 3, MATH_ECONOMICS, 3, 4, .pedagogyGrade = 5} };
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			printTopStudents(students);
			std::string text = buffer.str();
			std::cout.rdbuf(old);
			Assert::IsTrue(text.find("Ivanov") != std::string::npos);
			Assert::IsTrue(text.find("Petrov") == std::string::npos);
			Assert::IsTrue(text.find("Sidorov") == std::string::npos);
		}
	};
}
