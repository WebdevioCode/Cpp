#include <iostream>
#include <random>


void game(int& userNumber, int& computerNumber, int& guesses, bool& win );
void winOrLose(bool& win);
void numberGen(int& computerNumber);

int main(){
   int guesses{};
   int userDiff{};
   int userNumber{};
   int computerNumber{};
   bool win = false;

   std::cout << "Choose difficulty\n(1)Easy\n(2)Medium\n(3)Hard\n> ";
   std::cin >> userDiff;

   switch(userDiff) {
      case 1: guesses = 15; std::cout << "Difficulty choosen\n"; break;
      case 2: guesses = 10; std::cout << "Difficulty choosen\n"; break;
      case 3 :guesses = 5;  std::cout << "Difficulty choosen\n"; break;
      default: std::cout << "Out of range 1-3 only";
   }
   numberGen(computerNumber);
   game(userNumber,computerNumber,guesses,win);
   winOrLose(win);
}

void game(int& userNumber, int& computerNumber, int& guesses, bool& win) {
    int guessesUsed{};
    while (guesses != 0 && !win) {
      userNumber = 0;

      guesses --;
      guessesUsed ++;

      std::cout << "Guess " << guessesUsed << std::endl;
      std::cout << "Guess the number (1-10)\n> ";
      std::cin >> userNumber;
      
      if (userNumber == computerNumber) {
         win = true;
      } else if (userNumber < computerNumber) {
         std::cout << userNumber <<" is lower | Guesses Left: " << guesses << std::endl;
      } else {
          std::cout << userNumber <<" is higher | Guesses Left: " << guesses << std::endl;
      }
   }
}

void winOrLose(bool& win) {
   if (win) {
      std::cout << "You win";
   } else {
      std::cout << "You lose";
   }
}

void numberGen(int& computerNumber) {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution random(1,10);

   computerNumber = random(gen);
}
