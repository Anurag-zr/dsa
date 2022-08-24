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


    ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow=fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        
        fast = head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
        
    }


    int main(){
        ListNode* head = create();
        ListNode *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = head->next->next->next;

        ListNode *startNodeOfCycle = detectCycle(head);
        int count = 1;
        temp = head;
        while(temp!=startNodeOfCycle || count!=0){
            
            if(temp==startNodeOfCycle)
                count--;

             cout << "->" << temp->val;
             temp = temp->next;
        }

        cout << endl;
    }