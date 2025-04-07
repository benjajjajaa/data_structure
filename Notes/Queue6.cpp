#include <iostream>
#include <queue>
using namespace std;

queue<string> myQueue;
char name[10];
int x;

int main(){
    for (x = 1; x <= 5; x++) {
        cout << "Enter a name: ";
        cin >> name;
        myQueue.push(name);
    }

    cout << "The names are: " << endl;
    while (!myQueue.empty()) {
        cout << myQueue.front() << endl;
        myQueue.pop();
    }
    return 0;
}