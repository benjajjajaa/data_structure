// A complete working C++ program to demonstrate all insertion methods on Linked List 
#include <iostream>
#include <cmath>
using namespace std; 

// A linked list node 
class Node 
{ 
    public:
        int data; 
        Node *next; 
}; 

/* Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = NULL; 
    new_node = new Node();
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

/* Given a node prev_node, insert a new node after the given  prev_node */
void insertAfter(Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) 
    { 
        cout << "the given previous node cannot be NULL" << endl;
        return; 
    } 

    Node* new_node = NULL;
    new_node = new Node();
    new_node->data  = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
} 

/* Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end  */
void append(Node** head_ref, int new_data) 
{   
    Node* new_node = NULL; 
    new_node = new Node();
    Node *last = *head_ref; 
    new_node->data  = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 

// This function prints contents of linked list starting from head 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << "->"; 
        node = node->next; 
    }
    cout << "NULL" << endl;
} 

/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
    head = new Node();
    //Set head to 5. So linked list becomes 5->NULL
    head->data = 5;

    // Insert 6.  So linked list becomes 5->6->NULL 
    append(&head, 6); 

    // Insert 1 at the beginning. So linked list becomes 1->5->6->NULL 
    push(&head, 1); 

    // Insert 4 at the end. So linked list becomes 1->5->6->4->NULL 
    append(&head, 4); 

    // Insert 8, after 7. So linked list becomes 1->5->8->6->4->NULL 
    insertAfter(head->next, 8); 

    cout << "Created Linked list is:"; 
    printList(head); 
    system("pause");

return 0; 
} 

