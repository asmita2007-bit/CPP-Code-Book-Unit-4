#include <cstring>
#include <fstream>
#include <iostream>

struct StudentRecord {
    int rollNumber;
    char name[30];
    float marks;
};

int main() {
    StudentRecord students[3]{};

    students[0].rollNumber = 101;
    std::strncpy(students[0].name, "Amit Patil",
                 sizeof(students[0].name) - 1);
    students[0].marks = 85.5F;

    students[1].rollNumber = 102;
    std::strncpy(students[1].name, "Neha",
                 sizeof(students[1].name) - 1);
    students[1].marks = 91.0F;

    students[2].rollNumber = 103;
    std::strncpy(students[2].name, "Ravi",
                 sizeof(students[2].name) - 1);
    students[2].marks = 78.0F;

    {
        std::ofstream outputFile("students.dat", std::ios::binary);

        if (!outputFile) {
            std::cerr << "Error: Could not create students.dat\n";
            return 1;
        }

        for (int i = 0; i < 3; ++i) {
            outputFile.write(
                reinterpret_cast<const char*>(&students[i]),
                sizeof(StudentRecord)
            );
        }
    }

    {
        std::ifstream inputFile("students.dat", std::ios::binary);

        if (!inputFile) {
            std::cerr << "Error: Could not open students.dat\n";
            return 1;
        }

        StudentRecord student;

        while (inputFile.read(
            reinterpret_cast<char*>(&student),
            sizeof(StudentRecord))) {

            std::cout << "Roll Number: "
                      << student.rollNumber << '\n';

            std::cout << "Name: "
                      << student.name << '\n';

            std::cout << "Marks: "
                      << student.marks << '\n';

            std::cout << "------------------\n";
        }
    }

    return 0;
}
