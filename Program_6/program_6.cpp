#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

std::string normalizeWord(const std::string& word) {
    std::string result;

    for (char ch : word) {
        unsigned char currentChar = static_cast<unsigned char>(ch);

        if (std::isalnum(currentChar)) {
            result += static_cast<char>(std::tolower(currentChar));
        }
    }

    return result;
}

int main() {
    std::ifstream inputFile("message.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::string searchWord;

    std::cout << "Enter word to search: ";
    std::cin >> searchWord;

    searchWord = normalizeWord(searchWord);

    std::string word;
    int count = 0;

    while (inputFile >> word) {
        word = normalizeWord(word);

        if (word == searchWord) {
            ++count;
        }
    }

    std::cout << "The word '" << searchWord
              << "' occurred " << count << " time(s).\n";

    return 0;
}
