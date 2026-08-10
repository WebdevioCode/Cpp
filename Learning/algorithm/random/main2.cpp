#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5,2,9,1,5,6};

    std::sort(nums.begin(), nums.end());

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
 }
