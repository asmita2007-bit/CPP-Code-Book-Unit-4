#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream sourceFile("message.txt");
    std::ofstream destinationFile("cpp_lines.txt");

    if (!sourceFile) {
        std::cerr << "Error: Could not open source file.\n";
        return 1;
    }

    if (!destinationFile) {
        std::cerr << "Error: Could not create destination file.\n";
        return 1;
    }

    std::string line;

    while (std::getline(sourceFile, line)) {
        if (line.find("C++") != std::string::npos) {
            destinationFile << line << '\n';
        }
    }

    sourceFile.close();
    destinationFile.close();

    std::cout << "C++ lines copied successfully to cpp_lines.txt\n";

    return 0;
}
