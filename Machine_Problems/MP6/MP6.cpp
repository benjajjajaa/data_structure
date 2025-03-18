#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void printArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printResult(int index, int comparisons) {
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout << "Total comparisons: " << comparisons << endl;
}

int linearSearch(int arr[], int size, int target, int &comparisons) {
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target, int &comparisons) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int target, int &comparisons) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        comparisons++;
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int size, int target, int &comparisons) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[min(step, size) - 1] < target) {
        comparisons++;
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }
    while (arr[prev] < target) {
        comparisons++;
        prev++;
        if (prev == min(step, size))
            return -1;
    }
    comparisons++;
    if (arr[prev] == target)
        return prev;
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printArray(arr, N);
    cout << "Enter the number to search for: ";
    cin >> target;
    
    int comparisons = 0;
    int result;
    
    cout << "\nUsing Linear Search:" << endl;
    result = linearSearch(arr, N, target, comparisons);
    printResult(result, comparisons);
    
    comparisons = 0;
    cout << "\nUsing Binary Search:" << endl;
    result = binarySearch(arr, 0, N - 1, target, comparisons);
    printResult(result, comparisons);
    
    comparisons = 0;
    cout << "\nUsing Interpolation Search:" << endl;
    result = interpolationSearch(arr, N, target, comparisons);
    printResult(result, comparisons);
    
    comparisons = 0;
    cout << "\nUsing Jump Search:" << endl;
    result = jumpSearch(arr, N, target, comparisons);
    printResult(result, comparisons);
    
    return 0;
}
