#include<iostream>
using namespace std;

int main() {
    int a[10];
    int ctr;
    for(ctr=0;ctr<=9;ctr++) {
        cout<<"Enter any Number= ";
        cin>>a[ctr];
    }
    cout<<"OUTPUT IN REVERSE ORDER"<<endl;
    for(ctr=9;ctr>=0;ctr--) {
    cout<<a[ctr]<<endl;
}
    return 0;
}