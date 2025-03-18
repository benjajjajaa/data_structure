#include <iostream>

using namespace std;
int ctr = 0; //adds ctr to count how many comparision is made

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

    cout <<"\n"<< ctr << " comparisons was made :)" <<endl; //we print the result to show how many comparison is made
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        ctr++; //defined again how many comparison was made to find the variable? which is 32
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = 10;
    int target = 12;

    printInitial(arr, size);
    int result = linearSearch(arr, size, target);
    printResult(result);

    return 0;
}