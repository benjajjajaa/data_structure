#include <iostream>
#include <cmath> //cmath library for mathematical functions.
using namespace std;

double calculateAverage(double num1, double num2) {
    return (num1 + num2) / 2.0; //average of two numbers
}

double sumOfSquares(double num1, double num2) {
    return (num1 * num1) + (num2 * num2); //calculate the sum of the squares
}

double squareOfSum(double num1, double num2) {
    double sum = num1 + num2; //calculate the square of the sum of two numbers
    return sum * sum;
}

int main() {
    double num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    //calculate and display results
    cout << "Average: " << calculateAverage(num1, num2) << endl;
    cout << "Sum of Squares: " << sumOfSquares(num1, num2) << endl;
    cout << "Square of Sum: " << squareOfSum(num1, num2) << endl;
    
    return 0;
}
