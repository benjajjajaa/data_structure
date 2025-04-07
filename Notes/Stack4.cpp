#include <iostream>
#include <stack>
using namespace std;

stack <string> myStack;
char name[10];
int x;

int main(){
    for (x = 1; x <= 5; x++) {
        cout << "Enter a name: ";
        cin >> name;
        myStack.push(name);
    }

    cout << "The names are: " << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << endl;
        myStack.pop();
    }
    return 0;
}