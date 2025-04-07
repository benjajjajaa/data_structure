#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> B;
    B.push(7);
    B.push(4);
    B.push(1);
    B.push(3);
    B.push(6);
    cout << "Queue size: " << B.size() << endl;
    cout << "Contents of queue: " << endl;
    while (!B.empty()) {
        cout << B.front() << ";" << B.back() << endl;
        B.pop();
    }
    return 0;
}