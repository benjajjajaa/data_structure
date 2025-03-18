#include <iostream>
using namespace std;

double calculateRetail(double wholesaleCost, double markupPercentage) {
    return wholesaleCost + (wholesaleCost * (markupPercentage / 100));
}

int main() {
    double wholesaleCost, markupPercentage;
    
    
    cout << "Enter the item's wholesale cost: ";
    cin >> wholesaleCost;
    
    cout << "Enter the markup percentage: ";
    cin >> markupPercentage;
    
    if (wholesaleCost < 0 || markupPercentage < 0) {
        cout << "Error: Wholesale cost and markup percentage must be non-negative." << endl;
    } else {
        
        double retailPrice = calculateRetail(wholesaleCost, markupPercentage);
        cout << "The item's retail price is: " << retailPrice << endl;
    }
    
    return 0;
}