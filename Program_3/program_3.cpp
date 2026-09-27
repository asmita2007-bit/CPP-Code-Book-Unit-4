#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream outputFile("message.txt", std::ios::app);

    if (!outputFile) {
        std::cerr << "Error: Could not open message.txt for appending\n";
        return 1;
    }

    std::string name;
    std::string date;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter current date: ";
    std::getline(std::cin, date);

    outputFile << name << " - " << date << '\n';

    outputFile.close();

    std::cout << "Name and date appended successfully.\n";

    return 0;
}
