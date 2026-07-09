#include <iostream>

namespace first {
    int x{50};
}

namespace second {
    int x{10};
}

int main() {
    int x = 5;

    std::cout << x << std::endl;
    std::cout << first::x << std::endl;
    std::cout << second::x << std::endl;
}
