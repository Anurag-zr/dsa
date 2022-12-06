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


    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;

        ListNode* oddPtr;
        ListNode* evnPtr;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        oddPtr = head;
        evnPtr = dummy;

        while(oddPtr->next!=NULL && oddPtr->next->next!=NULL){
            evnPtr->next = oddPtr->next;
            evnPtr = evnPtr->next;
            oddPtr->next = evnPtr->next;
            oddPtr = oddPtr->next;

        }

        if(oddPtr->next){
            evnPtr->next = oddPtr->next;
            evnPtr=evnPtr->next;
        }

        evnPtr->next=NULL;
        oddPtr->next = dummy->next;

        return head;
    }

void printLL(ListNode *temp){
    while(temp!=NULL){
        cout << "->" << temp->val;
        temp = temp->next;
    }

    cout << endl;
}

int main(){
    ListNode *head = create();
    head = oddEvenList(head);
    printLL(head);
}