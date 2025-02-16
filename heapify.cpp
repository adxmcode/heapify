#include <iostream>
#include <vector>

void heapifyFunction(std::vector<int>&array, int n, int t) {
    int left = (2 * t) + 1;
    int right = (2 * t) + 2;

    int largest = t;
    if (left < n){
        if(array[left] > array[largest]) {
            largest = left;
        }
    }
    if (right < n) {
        if(array[right] > array[largest]) {
            largest = right;
        }
    }

    if (largest != t) {
        std::swap(array[t], array[largest]);
        heapifyFunction(array, n, largest);
    }
}

void heapifyEntire(std::vector<int>& array) {
    int n = array.size();

    for (int i = (n/2) - 1; i >= 0; i--) {
        heapifyFunction(array, n, i);
    }
}

void printArray(std::vector<int>& test) {
    for (size_t i = 0; i < test.size(); i++) {
        std::cout << test[i] << " ";
    }
   std::cout << std::endl;
}

int main() {
    std::vector<int>test = {45, 12, 16, 12, 19, 1, 3, 4, 6, 5, 2};
    std::cout << "Before: ";
    printArray(test);
    heapifyEntire(test);
    std::cout << "After Heapify: ";
    printArray(test);
    return 0;
}