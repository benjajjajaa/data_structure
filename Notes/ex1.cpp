#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class students {
public:
	string name;
	string id;
	double math;
	double science;
	double english;
	double filipino;
	double hekasi;


public:
	double studentave() {
		double average = (math + science + english + filipino + hekasi)/5;
		return average;
	}

	void setData(string n, string i, int m, int s, int e, int f, int h) {
		name = n;
		id = i;
		math = m;
		science = s;
		english = e;
		filipino = f;
		hekasi = h;
	}

	void displayInfo() {
		cout << studentave() << endl;
	}
	
	void displayID() {
		cout << "ID: " << id <<endl;
	}
};

    void insertionSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) { //2nd to the last element
        double key = arr[i]; //assigns the current element to the variable key
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { // it will continue as long as the j is non-negative
            arr[j + 1] = arr[j]; //use toshift the element
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(const vector<double>& arr) {
    for (double num : arr) { //range based 
        cout << num << " ";
    }
    cout << endl;
}


int main() {
	students Laraquel, Rance, Gaspi, Untalan, Aldeger;
	Laraquel.setData("Laraquel", "20221130923", 79, 81, 85, 95, 76);
	Rance.setData("Rance", "20241113019", 76, 82, 86, 97, 91);
	Gaspi.setData("Gaspi", "20241120810", 77, 80, 87, 92, 82);
	Untalan.setData("Untalan", "20241100947", 78, 89, 89, 81, 75);
	Aldeger.setData("Aldeger", "20241100023475", 79, 84, 90, 88, 80);
    
    
    cout << "Average:" << endl;
    Untalan.displayInfo(); 
    Laraquel.displayInfo();
    Gaspi.displayInfo();
    Aldeger.displayInfo();
    Rance.displayInfo();
    
    vector<double> arr = {Untalan.studentave(), Laraquel.studentave(), Gaspi.studentave(), Aldeger.studentave(), Rance.studentave()};
    
    cout << "sorted average" << endl;
	insertionSort(arr);
	printArray(arr);
	
	cout << "Average:" << endl;
    Laraquel.displayID(); 
    Rance.displayID();
    Gaspi.displayID();
    Untalan.displayID();
    Aldeger.displayID();
	
	stack <long int> A;
    A.push (20221130923);
    A.push (20241113019);
    A.push (20241120810);
    A.push (20241100947);
    A.push (20241100023475);
	
	
	cout << "Size of A: " << A.size() << endl;
    cout << "Contents of A: " << endl;
    while (!A.empty()) {
        cout << A.top() << endl;
        A.pop();
    }
    cout << endl;
    
	return 0;
}