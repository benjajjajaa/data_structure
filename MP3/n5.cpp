#include <iostream>
#include <iomanip>
using namespace std;

const double SQFT_PER_GALLON = 115.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_COST_PER_HOUR = 120.0;

// Function to calculate the number of gallons of paint required
double calculateGallons(double totalSqFt) {
    return totalSqFt / SQFT_PER_GALLON;
}

// Function to calculate the hours of labor required
double calculateLaborHours(double totalGallons) {
    return totalGallons * HOURS_PER_GALLON;
}

// Function to calculate the cost of the paint
double calculatePaintCost(double totalGallons, double paintPrice) {
    return totalGallons * paintPrice;
}

// Function to calculate labor charges
double calculateLaborCharges(double totalHours) {
    return totalHours * LABOR_COST_PER_HOUR;
}

// Function to calculate total cost
double calculateTotalCost(double paintCost, double laborCost) {
    return paintCost + laborCost;
}

int main() {
    int numRooms;
    double paintPrice, totalSqFt = 0.0;
    
    // Get user input
    cout << "Enter the number of rooms to be painted: ";
    cin >> numRooms;
    
    cout << "Enter the price of paint per gallon: ";
    cin >> paintPrice;
    
    for (int i = 1; i <= numRooms; i++) {
        double roomSqFt;
        cout << "Enter the square feet of wall space for room " << i << ": ";
        cin >> roomSqFt;
        totalSqFt += roomSqFt;
    }
    
    // Calculate required values
    double totalGallons = calculateGallons(totalSqFt);
    double totalHours = calculateLaborHours(totalGallons);
    double paintCost = calculatePaintCost(totalGallons, paintPrice);
    double laborCost = calculateLaborCharges(totalHours);
    double totalCost = calculateTotalCost(paintCost, laborCost);
    
    // Display the results
    cout << fixed << setprecision(2);
    cout << "\nPaint Job Estimate:\n";
    cout << "Gallons of Paint Required: " << totalGallons << endl;
    cout << "Hours of Labor Required: " << totalHours << endl;
    cout << "Cost of Paint: P" << paintCost << endl;
    cout << "Labor Charges: P" << laborCost << endl;
    cout << "Total Cost of the Paint Job: P" << totalCost << endl;
    
    return 0;
}
