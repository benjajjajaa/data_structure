#include<iostream>
using namespace std;

int main() {
    int num[10];
    int temp;

//INPUT FOR ARRAY
    for(int i = 0; i < 10; i++) {
        cout << "Enter a number: ";
        cin >> num[i];
    }

//BUBBLE SORT ALGORITHM
    for (int i = 0 ; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (num[i] > num[j]) {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }

//OUTPUT
    for(int i = 0; i < 10; i++) {
    cout << num[i] << endl;
    }

    system("pause");
}