#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{int data;
node* next;
};
int x,sum;
node* n;
node* t;
node* h;
main()
{  n= new node;
	t=n;
	h=n;
	for (x=1;x<=5;x++)
	{   
		cout<<"enter a data: ";
		cin>>n->data;
		sum= n->data + sum;
		n= new node;
		t->next=n;
		t=n;
		
	}
	for (x=1;x<=5;x++)
	{   
		cout<<h->data<<endl;
		h=h->next;
				
	}

	cout<<endl<<"sum="<<sum;
}

