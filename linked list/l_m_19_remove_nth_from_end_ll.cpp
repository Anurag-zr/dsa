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



    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy =new ListNode();
        dummy->next = head;
        ListNode *slow=dummy;
        ListNode *fast = dummy;
        
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
         ListNode* node = slow->next;
        if(slow->next==head){
            head = head->next;
        }
        
        slow->next = slow->next->next;
        delete(node);
        
        return head;
        
    }


int main(){
    ListNode *head = create();
    printLL(head);
    head = removeNthFromEnd(head, 2);
    cout << "after deletion" << endl;
    printLL(head);
}