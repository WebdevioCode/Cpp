#include <iostream>
#include <random>

int multi(int x, int y);
void randomNumberGen(int& num1, int& num2);

int main() {
    int correct{};
    int incorrect{};
    int questionsLeft{};
    int questions{};
    int round{};
    std::cout << "How many questions would you like\n> ";
    std::cin >> questions;

    questionsLeft = questions;

    while (questionsLeft != 0) {
        int num1{};
        int num2{};
        randomNumberGen(num1, num2);
        randomNumberGen(num1, num2);
        int answer = multi(num1,num2);
        int userAnswer{};

        round ++;


        std::cout << "Question " << round << std::endl;
        std::cout << num1 << " x " << num2 << " = ";
        std::cin >> userAnswer;
        
        questionsLeft --;

        if (userAnswer == answer) {
            correct ++;
            std::cout << "Correct | Questions left " << questionsLeft << std::endl; 
        } else {
            incorrect ++;
            std::cout << "Incorrect | Questions left " << questionsLeft << std::endl; 
        }
    }

    std::cout << "RESULTS" << std::endl;
    std::cout << "Correct: " << correct << std::endl;
    std::cout << "Incorrect: " << incorrect << std::endl;
    std::cout << "Questions: " << questions << std::endl;
}
void randomNumberGen(int& num1, int& num2) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(2, 10);

    static bool toggle = true; 

    if (toggle) {
        num1 = random(gen);
    } else {
        num2 = random(gen);
    }

    toggle = !toggle; 
}
int multi(int x, int y) {
    return x * y;
}
