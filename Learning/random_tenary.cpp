#include <iostream>

int main() {
   int grade{};

    std::cout << "Enter the grade you got\n> ";
    std::cin >> grade;

   grade >=50 ? std::cout << "You passed" : std::cout << "You failed"; 
}
