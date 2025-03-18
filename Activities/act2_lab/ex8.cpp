#include<iostream>
using namespace std;

int main() {
int A[5][5];
int row, col, sum, prod;

//INPUT FOR ARRAY
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Enter a number: ";
            cin >> A[i][j];
        }
    }

//OUTPUT
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            cout << A[i][j] << " ";
        }
            cout << endl;
    }

    sum = A[0][0] + A[1][1] + A[2][2] + A[3][3] + A[4][4];
    prod = A[0][4] * A[1][3] * A[2][2] * A[3][1] * A[4][0];
    cout <<"The sum of the elements in the main diagonal is: " << sum << endl;
    cout <<"The product of the elements in the secondary diagonal is: " << prod << endl;
    system("pause");
}