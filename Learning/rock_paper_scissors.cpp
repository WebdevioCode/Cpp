#include <iostream>
#include <random>
#include <cstdlib>

void randomNumberGen(int& computerNumber, std::string& computerChoice);

int main() {
   using std::cout;
   using std::cin;
   using std::string;

   int computerNumber{};
   string computerChoice{};
   string user{};

   randomNumberGen(computerNumber, computerChoice);

   system("cls");
   cout << "Enter rock, paper, scissors\n> ";
   cin >> user;

   bool win = (user == "rock" && computerChoice == "paper") ||
              (user == "scissors" && computerChoice == "paper") ||
              (user == "rock" && computerChoice == "scissors");

   system("cls");

   if (win) {
      cout << "You win\nYour choice: " << user << std::endl << "Computer choice: " << computerChoice; 
   } else if (user == computerChoice) {
      cout << "You drawed\nYour choice: " << user << std::endl << "Computer choice: " << computerChoice; 
   } else {
      cout << "You lost\nYour choice: " << user << std::endl << "Computer choice: " << computerChoice; 
   }
}

void randomNumberGen(int& computerNumber, std::string& computerChoice) {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> random(1,3);

   computerNumber = random(gen);
   
   switch(computerNumber) {
      case 1: computerChoice = "rock"; break;
      case 2: computerChoice = "paper"; break;
      case 3: computerChoice = "scissors"; break;
   }
} 
