#include <iostream>
#include <string>

class bankAccount {
    private:
        std::string owner{};
        double balance{};
        int pin{};

    public:
        bankAccount(std::string accountHolder, double Startingbalance , int makingPin) {
            owner = accountHolder;
            pin = makingPin;
            if (Startingbalance > 0) {
                balance = Startingbalance;
            } else {
                balance = 0;
            }
        }

        void disposit(double amount) {
            if (amount > 0) {
                balance += amount;
                std::cout << "Disposited " << amount;
            } else {
                std::cout << "You cant disposit 0 pound";
            }
        }

        void withdraw(double amount) {
            if (amount > balance) {
                std::cout << "You dont have enough money";
            } else if (amount <= 0) {
                std::cout << "You cant take out 0 pound";
            } else {
                balance -= amount;
                std::cout << "Withdrawn " << amount << std::endl;
                std::cout << "Balance " << balance;
            }
        }
        
        double showMoney(){
            return balance;
        }

        int showPin() {
            return pin;
        }
};


int main() {
    int choice{};
    std::string name{};
    int pin{};

    std::cout << "Enter the name off your account\n >_";
    std::getline(std::cin, name);

    std::cout << "Enter account pin\n >_";
    std::cin >> pin;

    bankAccount banker1(name, 50.00, pin);
    std::cout << "\nWelcome to your bank account " << std::endl;

    do
    {
       std::cout << std::endl << name << "'s account\n"
                << "(1)View balance\n"
                << "(2)Withdraw money\n"
                << "(3)Disposit money\n"
                << "(4)View pin\n"
                << "(5)Exit program\n >_";
       std::cin >> choice;

       double amount{};
       
       switch (choice) {
        case 1: 
            std::cout << "Balance " << banker1.showMoney(); 
            break;
        case 2:
            std::cout << "Enter the amount you would like to withdraw\n >_";
            std::cin >> amount;
            banker1.withdraw(amount);
            break;
        case 3:
            std::cout << "Enter the amount you would like to disposit\n >_";
            std::cin >> amount;
            banker1.disposit(amount);
            break;
        case 4:
            std::cout << "You pin is " << banker1.showPin();
            break;
        case 5:
            std::cout << "Programed exited\nGoodbye";
            break;
       }
    } while (choice != 5);
}
