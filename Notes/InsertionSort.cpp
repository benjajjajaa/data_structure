#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) { //2nd to the last element
        int key = arr[i]; //assigns the current element to the variable key
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { // it will continue as long as the j is non-negative
            arr[j + 1] = arr[j]; //use toshift the element
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) { //range based 
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    printArray(arr);
    
    insertionSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}