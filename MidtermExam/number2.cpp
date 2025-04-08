//2
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct FoodItem { //keyword
    string name;
    int shelfLife;
};

void selectionSort(vector<FoodItem>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].shelfLife < arr[minIndex].shelfLife) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(const vector<FoodItem>& arr) {
    for (const auto& item : arr) {
        cout << item.name << " ";
    }
    cout << endl;
}

int main() {
    vector<FoodItem> arr = {
        {"mangoes", 60},
        {"apple", 38},
        {"c2_red", 360},
        {"bukopie", 120},
        {"magic_sarap", 520},
        {"c2_green", 360},
        {"boy_bawang", 400},
        {"banana", 24}
    };
    
    cout << "Original array: ";
    printArray(arr);
    
    selectionSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}