#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inputFile("students.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    std::string line;

    std::cout << std::left
              << std::setw(12) << "Roll No."
              << std::setw(20) << "Name"
              << std::setw(10) << "Marks"
              << '\n';

    std::cout << "------------------------------------------\n";

    while (std::getline(inputFile, line)) {
        std::stringstream record(line);

        std::string rollText;
        std::string name;
        std::string marksText;

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            std::cout << std::left
                      << std::setw(12) << rollText
                      << std::setw(20) << name
                      << std::setw(10) << marksText
                      << '\n';
        }
    }

    return 0;
}
