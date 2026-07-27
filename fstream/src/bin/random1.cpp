#include <iostream>
#include <fstream>
#include <limits>

int main() {
    std::fstream file("data.txt", std::ios::out);

    if (file.is_open()){
        std::string name1{}, name2;
        int score1{}, score2{};

        std::cout << "Enter name to save score\n>_";
        std::getline(std::cin, name1);
        std::cout << "Enter score\n>_";
        std::cin >> score1;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter player 2 name to save score\n>_";
        std::getline(std::cin, name2);
        std::cout << "Enter score\n>_";
        std::cin >> score2;

        file << name1 << " " << score1 << "\n";
        file << name2 << " "<< score2 << "\n";
        file.close();
    }

    file.open("data.txt", std::ios::in);

    if (file.is_open()) {
        std::string name;
        int score;

        while (file >> name >> score) {
            std::cout << name << " | " << score << "\n";
        }
        file.close();
    } 

    return 0;
}
