#include <iostream>
#include <fstream>
#include <vector>

#include "normalize.hpp"

int main() {
    std::ifstream file("test.cpp");

    if (!file) {
        std::cerr << "Failed to open test.cpp\n";
        return 1;
    }

    std::vector<std::string> words = normalize(file);

    std::cout << std::endl;
    for (const auto& word : words) {
        std::cout << word << "\n";
    }
    std::cout << std::endl;

    return 0;
}