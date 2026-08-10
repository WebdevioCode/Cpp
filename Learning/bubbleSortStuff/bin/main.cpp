#include <iostream>
#include <vector>
#include <utility>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            std::swap(arr[j], arr[j + 1]);
            swapped = true;
            }
        } 
        if (!swapped) {
            break;
        }
    }   
}


int main() {
    std::vector<int> nums = {64,34,25,12,22,11,90};

    bubbleSort(nums);

    std::cout << "array sorted";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << '\n';
    return 0;
}
