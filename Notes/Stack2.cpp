#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> A;
    int x, n, ctr;

    cout << "Enter the size of the stack: ";
    cin >> x;

    for (ctr = 1; ctr <= x; ctr++) {
        cout << "Enter any element: ";
        cin >> n;
        A.push(n);
    }

    cout << "Stack size: " << A.size() << endl;

    cout << "Stack contents: " << endl;
    while (!A.empty()) {
        cout << A.top() << endl;
        A.pop();
    }

    cout << endl;
    return 0;
}