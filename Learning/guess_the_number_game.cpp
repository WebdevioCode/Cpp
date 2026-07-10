#include <iostream>
#include <random>
#include <cstdlib>

void randomNumberMaker(int & computer);

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    int user{};
    int computer{};
    int guess{0};
    int guessesLeft{5};
    int hints{};

    randomNumberMaker(computer);

    do
    {
        system("cls");

        int temp{};
        cout << "Guess the number (1-10) "<< endl;
        cout << "You have " << guessesLeft << " guesses left\n> ";
        cin >> user;
        guessesLeft --;
        guess ++;


        if (user > computer ) {
            int hint{};
            cout << user << " is not the number" << endl;
            cout << "(1)Hint" << endl;
            cout << "(2) Continue" << endl;
            cin >> hint;
            
            switch (hint) {
                case 1: cout << user << " is higher than the number" << endl; hints ++;
                        cout << "Press 1 to continue\n> ";
                        cin >> temp;
                        break;
                case 2: continue;
            }
        } else if (user < computer){
            int hint{};
            cout << user << " is not the number" << endl;
            cout << "(1) Hint" << endl;
            cout << "(2) Continue" << endl;
            cin >> hint;
            
            switch (hint) {
                case 1: cout << user << " is lower than the number " << endl; hints ++;
                        cout << "Press 1 to continue\n> ";
                        cin >> temp;
                        break;
                case 2: continue;
            }
        }
    } while (guessesLeft !=0 && user != computer);
    if (user == computer) {
        cout << "You got it!" << endl;
        cout << "Computer number: " << computer << endl;
        cout << "Guesses: " << guess << endl;
        cout << "Hints used: " << hints << endl;;
    } else {
        cout << "You didnt get it unlucky" << endl;
        cout << "Computer number: " << computer << endl;

    }
}

void randomNumberMaker(int & computer) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(1,10);
    computer = random(gen);
}
