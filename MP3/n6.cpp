#include <iostream>
using namespace std;

// Function prototypes
void showKilometers(double meters);
void showInches(double meters);
void showFeet(double meters);
void showMenu();

int main() {
    double meters;
    int choice;

    // Input distance in meters
    cout << "Enter a distance in meters: ";
    cin >> meters;

    // Validate input for negative distance
    if (meters < 0) {
        cout << "Distance cannot be negative. Exiting program." << endl;
        return 1;
    }

    // Keep displaying the menu until the user chooses to quit
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showKilometers(meters);
                break;
            case 2:
                showInches(meters);
                break;
            case 3:
                showFeet(meters);
                break;
            case 4:
                cout << "Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Function to display conversion to kilometers
void showKilometers(double meters) {
    double kilometers = meters * 0.001;
    cout << meters << " meters is " << kilometers << " kilometers." << endl;
}

// Function to display conversion to inches
void showInches(double meters) {
    double inches = meters * 39.37;
    cout << meters << " meters is " << inches << " inches." << endl;
}

// Function to display conversion to feet
void showFeet(double meters) {
    double feet = meters * 3.281;
    cout << meters << " meters is " << feet << " feet." << endl;
}

// Function to display the menu
void showMenu() {
    cout << "1. Convert to kilometers" << endl;
    cout << "2. Convert to inches" << endl;
    cout << "3. Convert to feet" << endl;
    cout << "4. Quit the program" << endl;
}
