
#include <bits/stdc++.h>
using namespace std;
  
// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;
  
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
// Linked list class to
// implement a linked list.
class Linkedlist {
  
public:
    Node* head;

    Linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);
  
    // Function to print the
    // linked list.
    void printList();
  
    // Function to delete the
    // node at given position
    // void deleteNode(int);
};


// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}
  
// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


    Node* reverseList(Node* head) {
        if(head == nullptr) return head;
        
        Node* dummy=nullptr;
        Node* temp = head->next;
        while(temp!=nullptr){
            head->next= dummy;
            dummy = head;
            head = temp;
            temp=temp->next;
        }
        
        head->next = dummy;
        
        return head;
    }


    int main(){
    Linkedlist list;
  
    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
  
    cout << "Elements of the list are: ";
  
    // Print the list
    list.printList();
    cout << endl;

    list.head = reverseList(list.head);


    cout << "reverse linked list" << endl;
    list.printList();
    cout << endl;
    }