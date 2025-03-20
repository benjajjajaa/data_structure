#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    cout << "\n|| Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "||" << endl;
}

void printResult(const string& sortName, int comparisons, int swaps) {
    cout << sortName << " - Comparisons: " << comparisons << ", Swaps: " << swaps << "\n";
}

vector<int> bubbleSort(vector<int> arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    return arr;
}

vector<int> insertionSort(vector<int> arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = key;
        swaps++;
    }
    return arr;
}

vector<int> selectionSort(vector<int> arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
    return arr;
}

void merge(vector<int>& arr, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        swaps++;
    }
    while (i < n1) { arr[k++] = L[i++]; swaps++; }
    while (j < n2) { arr[k++] = R[j++]; swaps++; }
}

void mergeSort(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

vector<int> performMergeSort(vector<int> arr, int& comparisons, int& swaps) {
    mergeSort(arr, 0, arr.size() - 1, comparisons, swaps);
    return arr;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    vector<int> numbers(N);
    cout << "Enter " << N << " numbers: ";
    for (int &num : numbers) cin >> num;
    
    int comparisons = 0, swaps = 0;
    vector<int> sortedArray = bubbleSort(numbers, comparisons, swaps);
    printArray(sortedArray);
    
    cout << "\n--- Sorting Results ---\n";
    printResult("\nBubble Sort", comparisons, swaps);
    comparisons = swaps = 0;
    insertionSort(numbers, comparisons, swaps);
    printResult("Insertion Sort", comparisons, swaps);
    comparisons = swaps = 0;
    selectionSort(numbers, comparisons, swaps);
    printResult("Selection Sort", comparisons, swaps);
    comparisons = swaps = 0;
    performMergeSort(numbers, comparisons, swaps);
    printResult("Merge Sort", comparisons, swaps);
    
    return 0;
}