#include <iostream>

using namespace std;

int main() {
    int height = 5; // height for the roof
    int width = 9;  // width for the house body

    // roof using a loop
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) { // adds space before each row of star
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) { // the stars increased by +2
            cout << "*"; // prints star
        }
        cout << endl;
    }
    
    // walls of the house
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) { // runs 9 times
            if (j == 0 || j == width - 1 || i == height - 1) { // stars being printed 
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
