#include <cctype>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputFile("message.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int punctuation = 0;

    char ch;

    while (inputFile.get(ch)) {
        unsigned char currentChar = static_cast<unsigned char>(ch);

        if (std::isalpha(currentChar)) {
            char lower = static_cast<char>(std::tolower(currentChar));

            if (lower == 'a' || lower == 'e' ||
                lower == 'i' || lower == 'o' ||
                lower == 'u') {
                ++vowels;
            } else {
                ++consonants;
            }
        } 
        else if (std::isdigit(currentChar)) {
            ++digits;
        } 
        else if (std::isspace(currentChar)) {
            if (ch == ' ') {
                ++spaces;
            }
        } 
        else if (std::ispunct(currentChar)) {
            ++punctuation;
        }
    }

    std::cout << "Vowels: " << vowels << '\n';
    std::cout << "Consonants: " << consonants << '\n';
    std::cout << "Digits: " << digits << '\n';
    std::cout << "Spaces: " << spaces << '\n';
    std::cout << "Punctuation: " << punctuation << '\n';

    return 0;
}
