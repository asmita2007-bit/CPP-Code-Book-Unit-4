#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream inputFile("message.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::string line;
    int lineNumber = 1;

    std::cout << "File Content:\n";

    while (std::getline(inputFile, line)) {
        std::cout << lineNumber << ". " << line << '\n';
        ++lineNumber;
    }

    inputFile.close();

    return 0;
}
