#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    struct ListNode *next;


    ListNode(){
        val = 0;
        next = NULL;
    }

    ListNode(int val){
        this->val = val;
        next = NULL;
    }

    ListNode(int val,ListNode* next){
        this->val = val;
        this->next = next;
    }
};




ListNode* create(){
    int data;
    ListNode *linkedList;

    //dynamically allocating memory for ll node
    linkedList = new ListNode;

    cout << "\nEnter data to be inserted "
         << "or type -1 for no insertion : ";

    //input from user
    cin >> data;

    if(data ==-1) return nullptr;

    //Assign value from user into linkedList
    linkedList->val = data;

    //Recursively call to create the 
    //next part of linked list

    cout << "Enter next node value of linked list: ";
    linkedList->next = create();

    return linkedList;
}


void printLL(ListNode *temp){
    while(temp!=NULL){
        cout << "->" << temp->val;
        temp = temp->next;
    }

    cout << endl;
}


    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        
        ListNode *temp = node->next;
        
        node->next =  node->next->next;
        delete(temp);
    }


    int main(){
        ListNode* head = create();
        ListNode *deleteThisNOde = head->next->next;
        cout << "before deletion: " << endl;
        printLL(head);
        deleteNode(deleteThisNOde);
        cout << "after deletion: " << endl;
        printLL(head);
    }