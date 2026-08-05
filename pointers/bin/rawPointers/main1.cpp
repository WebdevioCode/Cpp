#include <iostream>

int main() {
    double* valPtr = new double(3.14);

    std::cout << "Address: " << valPtr << '\n';
    std::cout << "Value: " << *valPtr << '\n';

    delete valPtr;

    valPtr = nullptr;

    std::cout << valPtr;
}
