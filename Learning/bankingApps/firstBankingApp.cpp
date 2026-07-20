#include <iostream>
void showMoney(double& money);
void withdrawMoney(double& money);
void depositMoney(double& money);

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    int user_input{};
    double money{50.0};
    while (true) {
        cout << "Bank" << endl;
        cout << "(1)View Balance" << endl;
        cout << "(2)WithDraw Money" << endl;
        cout << "(3)Deposit Money" << endl;
        cout << "(4)Exit" << endl;
        cout << "> ";
        cin >> user_input;

        switch (user_input) {
            case 1: showMoney(money); break;
            case 2: withdrawMoney(money); break;
            case 3: depositMoney(money); break;
            case 4: return 0;
            default: cout << "Only 1-4";
    }
    }
    return 0;
}

void showMoney(double& money) {
    int leave;
    std::cout << "Balance: "<< money << std::endl;
    std::cout << "Press 1 to leave"<< std::endl;
    std::cin >> leave;
}
void withdrawMoney(double& money) {
    int leave;
    double amount{};
    std::cout << "Enter the amount you would like to take out\n> " << std::endl;
    std::cin >> amount;
    if (money <= 0) {
        std::cout << "You dont have any money" << std::endl;
        money = 0;
    } else if (amount > money) {
        std::cout << "You have dont enough money" << std::endl;
    } else {
        money -= amount;
        std::cout << "Balance: " << money << std::endl;
        amount = 0;
    }
    std::cout << "Press 1 to leave"<< std::endl;
    std::cin >> leave;
}
void depositMoney(double& money) {
    int leave;
    double amount{};
    std::cout << "Enter the amount you like to disposit\n> " << std::endl;
    std::cin >> amount;
    money += amount;
    std::cout << "New Balance: " << money << std::endl;
    amount = 0;
    std::cout << "Press 1 to leave"<< std::endl;
    std::cin >> leave;
}

