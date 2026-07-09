#include <iostream>

int add(int x, int y);
int sub(int x, int y);
int multi(int x, int y);
int divison(int x, int y);
int main() {
    int num1{};
    int num2{};
    char symbol{};

    std::cout << "Enter first number\n> ";
    std::cin >> num1;
    std::cout << "Enter second number\n> ";
    std::cin >> num2;
    std::cout << "Enter either\n+ \n- \n/ \nx \n>  ";
    std::cin >> symbol;

    int answer{};

    switch (symbol) {
        case '+': 
            answer = add(num1,num2);
            std::cout << num1 << " + " << num2 << " = " << answer;
            break;
        case '-':
            answer = sub(num1,num2);
            std::cout << num1 << " - " << num2 << " = " << answer;
            break;
        case '/':
            answer = divison(num1,num2);
            std::cout << num1 << " / " << num2 << " = " << answer;
            break;    
        case 'x':
            answer = multi(num1,num2);
            std::cout << num1 << " x " << num2 << " = " << answer;
            break;
    }
}


int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
int multi(int x, int y) {
    return x * y;
}
int divison(int x, int y) {
    return x / y;
}
