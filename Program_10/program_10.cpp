#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("navigation.txt");

    if (!file) {
        std::cerr << "Error: Could not open navigation.txt\n";
        return 1;
    }

    file.seekg(-1, std::ios::end);

    char lastCharacter;
    file.get(lastCharacter);

    std::cout << "Last character: " << lastCharacter << '\n';

    file.close();

    return 0;
}
