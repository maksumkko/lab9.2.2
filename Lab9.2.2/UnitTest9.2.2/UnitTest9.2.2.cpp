#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9.2.2/Lab9.2.2.cpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest922
{
	TEST_CLASS(UnitTest922)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            std::ostringstream output;
            std::streambuf* originalCoutBuffer = std::cout.rdbuf(); // Save original buffer
            std::cout.rdbuf(output.rdbuf()); // Redirect std::cout to output string stream

            // Call the function with some test values
            display_counts(5, 10, 2, 3, 4);

            // Restore original buffer
            std::cout.rdbuf(originalCoutBuffer);

            // Expected output
            std::string expectedOutput =
                "Character counts:\n"
                "Alphabetic: 5\n"
                "Digits: 10\n"
                "Control characters: 2\n"
                "Punctuation: 3\n"
                "Other characters: 4\n";

            // Check if the output matches the expected output
            Assert::AreEqual(expectedOutput, output.str());
		}
	};
}