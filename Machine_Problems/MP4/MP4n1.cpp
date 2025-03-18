#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;
    char choice;
    int value;
    
    do {
        cout << "\n[A] Push Data";
        cout << "\n[B] Pop Data";
        cout << "\n[C] Show Top";
        cout << "\n[D] Show Size";
        cout << "\n[E] Quit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        
        switch (toupper(choice)) {
            case 'A':
                cout << "Enter value to push: ";
                cin >> value;
                myStack.push(value);
                cout << "Value pushed!" << endl;
                break;
            case 'B':
                if (!myStack.empty()) {
                    cout << "Popped value: " << myStack.top() << endl;
                    myStack.pop();
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;
            case 'C':
                if (!myStack.empty()) {
                    cout << "Top value: " << myStack.top() << endl;
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;
            case 'D':
                cout << "Stack size: " << myStack.size() << endl;
                break;
            case 'E':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (toupper(choice) != 'E');
    
    return 0;
}
