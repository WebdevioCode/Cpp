#include <iostream>
#include <string>

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    int num{};
    cout << "Enter a day of the week (1-7)\n> " ;
    cin >> num;
        
    switch (num) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
        default: cout << "You can only choose between 1-7"; break;
    }
}
