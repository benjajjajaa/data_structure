#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{int data;
node* next;
node* prev;
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
		n->prev=t;
		t=n;
		
	}
	for (x=1;x<=5;x++)
	{   
		cout<<h->data<<endl;
		h=h->next;
				
	}

	for (x=1;x<=5;x++)
	{   n=n->prev;
		cout<<n->data<<endl;
					
	}
	cout<<endl<<"sum="<<sum;
}

