#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss,token,delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string line = "apple,banana,cherry,date";
    std::vector<std::string> fruits = split(line, ',');

    for (const auto& fruit : fruits) {
        std::cout << "Found Fruit:" << fruit << "\n";
    }
}
