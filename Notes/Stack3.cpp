#include <iostream>
//#include <conio.h>
#include <stack>
using namespace std;

stack<int> myStack1;
stack<int> myStack2;
int x, n;

int main() {
    for (x = 1; x <= 5; x++) {
        cout << "Enter a number: ";
        cin >> n;
        myStack1.push(n);
    }

    cout << "Contents of myStack1: " << endl;
    while (!myStack1.empty()) {
        cout << myStack1.top() << endl;
        myStack2.push(myStack1.top());
        myStack1.pop();
    }

    cout << "Transfering to myStacks2: \n" << endl;
    while (!myStack2.empty()) {
        cout << myStack2.top() << endl;
        myStack2.pop();
    }

    return 0;
}