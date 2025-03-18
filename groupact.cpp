#include<iostream>
using namespace std;

void odd (int);
void even (int);

int main() {
	int i;
	do {
    	cout << "Please, enter number (0 to exit): ";
    	cin >> i;
    	odd (i); //determines if it is odd?
  	} while (i != 0); //when entered zero the program will stop.
  	system("pause"); //can be removed.
}

void odd (int x) { //defines that this function is for odd.
  	if ((x % 2) != 0) //Checks if the remainder of x divided by 2 is not 0. This means the number is odd.
  		cout << "It is odd.\n"; //prints "it is odd"
  	else //if zero then even
		even (x);
}

void even (int x) {
  	if ((x % 2) == 0) //Checks if the remainder of x divided by 2 is 0. This means the number is even.
  		cout << "It is even.\n";
  	else 
	  	odd (x);
}


