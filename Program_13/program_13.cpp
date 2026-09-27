#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string fileName;
    std::ifstream inputFile;

    while (true) {
        std::cout << "Enter file name: ";
        std::getline(std::cin, fileName);

        inputFile.open(fileName);

        if (inputFile) {
            break;
        }

        std::cout << "Invalid file. Please try again.\n";
        inputFile.clear();
    }

    std::string line;

    std::cout << "\nFile Content:\n";

    while (std::getline(inputFile, line)) {
        std::cout << line << '\n';
    }

    inputFile.close();

    return 0;
}
