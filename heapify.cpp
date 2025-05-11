#include <iostream>
#include <vector>

void heapifyMaxFunction(std::vector<int>&array, int n, int t) {
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
        heapifyMaxFunction(array, n, largest);
    }
}

void heapifyMinFunction(std::vector<int>&array, int n, int t) {
    int left = (2 * t) + 1;
    int right = (2 * t) + 2;

    int smallest = t;
    if (left < n){
        if(array[left] < array[smallest]) {
            smallest = left;
        }
    }
    if (right < n) {
        if(array[right] < array[smallest]) {
            smallest = right;
        }
    }

    if (smallest != t) {
        std::swap(array[t], array[smallest]);
        heapifyMaxFunction(array, n, smallest);
    }
}

void heapifyMaxEntire(std::vector<int>& array) {
    int n = array.size();

    for (int i = (n/2) - 1; i >= 0; i--) {
        heapifyMaxFunction(array, n, i);
    }
}

void heapifyMinEntire(std::vector<int>& array) {
    int n = array.size();

    for (int i = (n/2) - 1; i >= 0; i--) {
        heapifyMinFunction(array, n, i);
    }
}

void printArray(std::vector<int>& test) {
    for (size_t i = 0; i < test.size(); i++) {
        std::cout << test[i] << " ";
    }
   std::cout << std::endl;
}

int main() {
    //Feel free to edit the test vector. 
    std::vector<int>test = {45, 12, 16, 12, 19, 1, 3, 4, 6, 5, 2};
    std::cout << "Before: ";
    printArray(test);
    heapifyMaxEntire(test);
    std::cout << "After Heapify Max: ";
    printArray(test);
    heapifyMinEntire(test);
    std::cout << "After Heapify Min: ";
    printArray(test);
    return 0;
}
