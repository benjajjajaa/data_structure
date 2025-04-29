// A complete working C++ program to demonstrate all  
// insertion before a given node  
#include <iostream>
using namespace std;

// A linked list node  
class Node { 
    public: 
        int data;  
        Node* next;  
        Node* prev;  
};  

/* Given a reference (pointer to pointer) to the head of a list  
and an int, inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data) {  
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    new_node->prev = NULL;  

    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  
    (*head_ref) = new_node;  
}  

/* Given a node as next_node, insert a new node before the given node */
void insertBefore(Node** head_ref, Node* next_node, int new_data) {  
/*1. check if the given next_node is NULL */
    if (next_node == NULL) {  
        printf("the given next node cannot be NULL");  
        return;  
    }  
    /* 2. allocate new node */
    Node* new_node = NULL;
    new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;  

    /* 4. Make prev of new node as prev of next_node */
    new_node->prev = next_node->prev;  

    /* 5. Make the prev of next_node as new_node */
    next_node->prev = new_node;  

    /* 6. Make next_node as next of new_node */
    new_node->next = next_node;  

    /* 7. Change next of new_node's previous node */
    if (new_node->prev != NULL)  
        new_node->prev->next = new_node;  
    /* 8. If the prev of new_node is NULL, it will be the new head node */
    else
        (*head_ref) = new_node; 

}  

// This function prints contents of linked list starting from the given node  
void printList(Node* node) {  
    Node* last;
    last = new Node();
    cout << "Traversal in forward direction:  ";
    while (node != NULL) {  
        cout << node->data << "->" ; 
        last = node;  
        node = node->next;  
    } 
    cout << "NULL" << endl;

    cout << "Traversal in reverse direction:  "; 
    while (last != NULL) {  
        cout << last->data << "->" ; 
        last = last->prev;  
    } 
    cout << "NULL" << endl;
}  

/* Driver program to test above functions*/
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
    head = new Node();
    head->data = 7;
    push(&head, 1);  
    push(&head, 4);  
    // Insert 8, before 1. So linked list becomes 4->8->1->7->NULL  
    insertBefore(&head, head->next, 8);  

    cout << "Created Doubly Linked List is: " << endl;
    printList(head);  
    system("pause") ;
    
}  
