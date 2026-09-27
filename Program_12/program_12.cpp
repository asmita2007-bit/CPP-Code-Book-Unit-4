#include <cstring>
#include <fstream>
#include <iostream>

struct StudentRecord {
    int rollNumber;
    char name[30];
    float marks;
};

void addRecord(std::ofstream& file,
               int rollNumber,
               const char* name,
               float marks) {

    StudentRecord student{};

    student.rollNumber = rollNumber;

    std::strncpy(
        student.name,
        name,
        sizeof(student.name) - 1
    );

    student.marks = marks;

    file.write(
        reinterpret_cast<const char*>(&student),
        sizeof(StudentRecord)
    );
}

int main() {
    {
        std::ofstream outputFile(
            "records.dat",
            std::ios::binary | std::ios::trunc
        );

        if (!outputFile) {
            std::cerr << "Error: Could not create records.dat\n";
            return 1;
        }

        addRecord(outputFile, 101, "Amit", 85.5F);
        addRecord(outputFile, 102, "Neha", 91.0F);
        addRecord(outputFile, 103, "Ravi", 78.0F);
    }

    std::ifstream inputFile("records.dat", std::ios::binary);

    if (!inputFile) {
        std::cerr << "Error: Could not open records.dat\n";
        return 1;
    }

    int targetRoll;

    std::cout << "Enter roll number to search: ";
    std::cin >> targetRoll;

    StudentRecord student;
    bool found = false;

    while (inputFile.read(
        reinterpret_cast<char*>(&student),
        sizeof(StudentRecord))) {

        if (student.rollNumber == targetRoll) {
            std::cout << "Record Found\n";
            std::cout << "Roll Number: "
                      << student.rollNumber << '\n';
            std::cout << "Name: "
                      << student.name << '\n';
            std::cout << "Marks: "
                      << student.marks << '\n';

            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Record not found.\n";
    }

    return 0;
}
