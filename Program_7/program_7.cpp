#include <fstream>
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::ofstream outputFile("students.txt", std::ios::app);

    if (!outputFile) {
        std::cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    int rollNumber;
    std::string name;
    double marks;
    std::string course;
    std::string mobile;

    std::cout << "Enter roll number: ";
    std::cin >> rollNumber;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter marks: ";
    std::cin >> marks;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter course name: ";
    std::getline(std::cin, course);

    std::cout << "Enter mobile number: ";
    std::getline(std::cin, mobile);

    outputFile << rollNumber << '|'
               << name << '|'
               << marks << '|'
               << course << '|'
               << mobile << '\n';

    std::cout << "Student record saved successfully.\n";

    return 0;
}
