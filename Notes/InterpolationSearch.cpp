#include <iostream>
#include <vector>

using namespace std;

void printInitialArray(const vector<int>& arr) {
    cout << "Initial array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void printResult(int index, int key) {
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array" << endl;
    }
}

int interpolationSearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // If the array has only one element
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        // Estimate the position of the key
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (key - arr[low]));

        // Check if the key is found
        if (arr[pos] == key) {
            return pos;
        }

        // If the key is larger, key is in the upper part
        if (arr[pos] < key) {
            low = pos + 1;
        } 
        // If the key is smaller, key is in the lower part
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23};
    int key = 18;

    printInitialArray(arr);
    int index = interpolationSearch(arr, key);
    printResult(index, key);

    return 0;
}