#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    queue<int> myQueue;
    stack<int> myStack;

    myQueue.push(8);
    myQueue.push(3);
    myQueue.push(6);
    myQueue.push(2);
    myQueue.push(5);

    cout << "Elements in Queue: " << endl;
    while (!myQueue.empty()) {
        cout << myQueue.front() << " " << endl;
        myStack.push(myQueue.front());
        myQueue.pop();
    }

    cout << "Elements in Stack: " << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << " " << endl;
        myStack.pop();
    }
    cout << endl;

    return 0;
}