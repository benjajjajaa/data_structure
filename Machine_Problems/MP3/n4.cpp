#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not a prime number
        }
    }
    return true; // No divisors found, it's a prime number
}

int main() {
    int number;
    
    // Get user input
    cout << "Enter an integer: ";
    cin >> number;
    
    // Check if the number is prime and display the result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }
    
    return 0;
}
