#include <iostream>
#include <fstream>
#include <cctype>   // For character classification macros
#include <cassert>  // For assert
#include <string>

void display_counts(int alphabetic, int digits, int control, int punctuation, int other) {
    std::cout << "Character counts:" << std::endl;
    std::cout << "Alphabetic: " << alphabetic << std::endl;
    std::cout << "Digits: " << digits << std::endl;
    std::cout << "Control characters: " << control << std::endl;
    std::cout << "Punctuation: " << punctuation << std::endl;
    std::cout << "Other characters: " << other << std::endl;
}

int main() {
    // Variables to count different types of characters
    int alphabetic_count = 0;
    int digit_count = 0;
    int control_count = 0;
    int punctuation_count = 0;
    int other_count = 0;

    // Get the range for digits from the user
    char min_digit, max_digit;
    std::cout << "Enter minimum digit (0-9): ";
    std::cin >> min_digit;
    std::cout << "Enter maximum digit (0-9): ";
    std::cin >> max_digit;

    // Ensure min_digit and max_digit are valid and within range
    assert(isdigit(min_digit) && isdigit(max_digit) && "Range limits must be digits.");
    assert(min_digit <= max_digit && "Minimum digit must be less than or equal to maximum digit.");

    // Open the file for reading
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }




    // Read characters from the file and classify them
    char ch;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            alphabetic_count++;
        }
        else if (isdigit(ch)) {
            digit_count++;
            // Assert if the digit is outside the specified range
            assert(ch >= min_digit && ch <= max_digit && "Digit out of specified range.");
        }
        else if (iscntrl(ch)) {
            control_count++;
        }
        else if (ispunct(ch)) {
            punctuation_count++;
        }
        else {
            other_count++;
        }
    }

    file.close();

    display_counts(alphabetic_count, digit_count, control_count, punctuation_count, other_count);

    return 0;
}