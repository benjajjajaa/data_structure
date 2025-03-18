#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;
    char choice;
    int value;
    
    do {
        cout << "\n[A] Push Data";
        cout << "\n[B] Pop Data";
        cout << "\n[C] Show Front";
        cout << "\n[D] Show Back";
        cout << "\n[E] Show Size";
        cout << "\n[F] Quit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        
        switch (toupper(choice)) {
            case 'A':
                cout << "Enter value to push: ";
                cin >> value;
                myQueue.push(value);
                cout << "Value pushed!" << endl;
                break;
            case 'B':
                if (!myQueue.empty()) {
                    cout << "Popped value: " << myQueue.front() << endl;
                    myQueue.pop();
                } else {
                    cout << "Queue is empty!" << endl;
                }
                break;
            case 'C':
                if (!myQueue.empty()) {
                    cout << "Front value: " << myQueue.front() << endl;
                } else {
                    cout << "Queue is empty!" << endl;
                }
                break;
            case 'D':
                if (!myQueue.empty()) {
                    cout << "Back value: " << myQueue.back() << endl;
                } else {
                    cout << "Queue is empty!" << endl;
                }
                break;
            case 'E':
                cout << "Queue size: " << myQueue.size() << endl;
                break;
            case 'F':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (toupper(choice) != 'F');
    
    return 0;
}
