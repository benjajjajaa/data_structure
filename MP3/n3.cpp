#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the perimeter of a square
double perimeterSquare(double side) {
    return 4 * side;
}

// Function to calculate the perimeter of a rectangle
double perimeterRectangle(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate the perimeter (circumference) of a circle
double perimeterCircle(double radius) {
    return 2 * M_PI * radius; // M_PI is a constant from <cmath>
}

int main() {
    double side, length, width, radius;
    
    // Get user input for square
    cout << "Enter the side length of the square: ";
    cin >> side;
    cout << "Perimeter of Square: " << perimeterSquare(side) << endl;
    
    // Get user input for rectangle
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Perimeter of Rectangle: " << perimeterRectangle(length, width) << endl;
    
    // Get user input for circle
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Perimeter of Circle: " << perimeterCircle(radius) << endl;
    
    return 0;
}
