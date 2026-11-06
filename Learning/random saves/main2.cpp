#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence = "C++ strings are pretty cool";
    std::stringstream ss(sentence);

    std::string word;
    int wordCount = 0;

    while (ss >> word) {
        wordCount ++;
        std::cout << "Word " << wordCount << ": " << word << "\n"; 
    } 
}