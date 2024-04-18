#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_11.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {

            Employee employee;


            std::istringstream iss("Ivanov II Director 2000 50000");
            std::cin.rdbuf(iss.rdbuf());


            inputEmployee(employee);


            Assert::AreEqual(std::string("Ivanov"), employee.surname);
            Assert::AreEqual(std::string("II"), employee.initials);
            Assert::AreEqual(std::string("Director"), employee.position);
            Assert::AreEqual(2000, employee.hire_year);
            Assert::AreEqual(50000.0, employee.salary);
        }
    };
}
