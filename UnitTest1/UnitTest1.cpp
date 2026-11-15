#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3B/Pair.h"
#include "../lab3.3B/Rational.h"
#include "../lab3.3B/Pair.cpp"
#include "../lab3.3B/Rational.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Pair p(5, 10);
            Assert::AreEqual(5, p.getFirst(), L"getFirst() має повернути 5");
            Assert::AreEqual(10, p.getSecond(), L"getSecond() має повернути 10");
        }

        TEST_METHOD(TestSetters)
        {
            Pair p;
            p.setFirst(7);
            p.setSecond(14);
            Assert::AreEqual(7, p.getFirst());
            Assert::AreEqual(14, p.getSecond());
        }

        TEST_METHOD(TestComparisonOperators)
        {
            Pair p1(3, 5);
            Pair p2(3, 4);
            Pair p3(4, 1);
            Pair p4(3, 5);

          
            Assert::IsTrue(p1 > p2, L"(3,5) має бути більше за (3,4)");
            Assert::IsTrue(p3 > p1, L"(4,1) має бути більше за (3,5)");
            Assert::IsTrue(p1 == p4, L"(3,5) має дорівнювати (3,5)");
            Assert::IsTrue(p2 < p1, L"(3,4) має бути менше за (3,5)");
            Assert::IsTrue(p1 != p2, L"(3,5) не має дорівнювати (3,4)");
        }
	};
}
