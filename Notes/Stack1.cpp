#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> A;
    A.push(5);
    A.push(3);
    A.push(2);
    A.push(4);
    A.push(7);

    cout << "Size of A: " << A.size() << endl;

    cout << "Contents of A: " << endl;
    while (!A.empty()) {
        cout << A.top() << endl;
        A.pop();
    }
    cout << endl;
    return 0;
}