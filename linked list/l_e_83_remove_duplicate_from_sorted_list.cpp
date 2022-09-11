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


    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==NULL) return head;
        
        ListNode* cur=head;
        ListNode* temp = cur;
        
        
        while(cur->next!=NULL){
            while(temp!=NULL && cur->val==temp->val){
                temp=temp->next;
            }
            
            if(temp==NULL) cur->next=temp;
            else{
               cur->next = temp;
                cur=temp;
            }
        }
        
        return head;
    }




int  main(){
    ListNode* head = create();

    head = deleteDuplicates(head);
    printLL(head);
}