#include <iostream>
#include <stdlib.h>
using namespace std;
int x[5],z,y,n,m,ctr,p;

int main() {
    p=5;
    ctr=0;
    
    system ("cls");
    
    for(z=0;z<5;z++){
        cout<<"Enter an integer: ";
        cin>>x[z];
    }

    system ("cls");
    cout<<"you entered: "<<endl;
    
    for(z=0;z<5;z++)
        cout<<x[z]<<endl;
        cout<<endl<<"Enter number to be deleted: ";
        cin>>n;

    for(z=0;z<p;z++){
        if(x[z]==n){
            for(m=z;m<p;m++){
            x[m]=x[m+1];
            }
        p=p-1;
        z=z-1;
        ctr++;
        }
    }   
    if(ctr==0)
        cout<<endl<<n<<" cannot be found"<<endl;

    else
        cout<<endl<<n<<" successfully deleted"<<endl;
        cout<<endl<<"The list are: "<<endl;

    for(z=0;z<=4-ctr;z++)
        cout<<x[z]<<endl;
}