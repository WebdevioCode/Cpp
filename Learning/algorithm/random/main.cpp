#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {12,3,45,7,23,1};

    std::sort(numbers.begin(), numbers.end());

    bool found = std::binary_search(numbers.begin(), numbers.end(), 23);

    if (found) {
        std::cout << "Number 23 was found in the array"; 
    }
    
    return 0;
 }
