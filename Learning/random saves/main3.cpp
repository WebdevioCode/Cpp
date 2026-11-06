#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::cout << "Type out a sentence ";
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::string word;
    int wordCount;

    while (ss >> word) {
        wordCount ++;
    }
    std::cout << "The sentence has " << wordCount << " words\n";

    return 0;
}