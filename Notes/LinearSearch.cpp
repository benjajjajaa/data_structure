#include <iostream>

using namespace std;

void printInitial(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printResult(int index) {
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {34, 7, 23, 32, 5, 62, 32, 2, 45, 67};
    int size = 10;
    int target = 32;

    printInitial(arr, size);
    int result = linearSearch(arr, size, target);
    printResult(result);

    return 0;
}