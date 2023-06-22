#include <iostream>
#include <fstream>
#include <string>

void opendat() {
    std::ifstream file("trym.dat"); // Replace "example.dat" with the actual file path

    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return ;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return ;
}
