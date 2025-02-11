#include <iostream>
#include <stdlib.h>
using namespace std;

char x[5];
char y;
int z;

int main(){
system ("cls");
    cout<<"Enter a name: ";
    cin>>x;
    cout<<"You entered "<<x<<endl;
    cout<<endl<<"Enter letter to search: ";
    cin>>y;

    for(z=0;z<=4;z++)
    if (y==x[z])
    cout<<y<<"is located at "<<"array["<<z<<"]"<<endl;
}