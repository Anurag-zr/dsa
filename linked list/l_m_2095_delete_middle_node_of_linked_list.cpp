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

    ListNode* deleteMiddle(ListNode* head) {
      ListNode* dummy = new ListNode(0);
        ListNode *slow,*fast;
        dummy->next = head;
        slow = fast =dummy;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            // cout<<slow->val<<fast->val<<endl;
            fast = fast->next->next;
            slow = slow->next;
        }
        
//         if(fast->next==NULL){//odd no of nodes exist
//             slow->next = slow->next->next;
//         }
        
//         if(fast->next->next == NULL){
            
//         }
        
        slow ->next = slow->next->next;
        
        
        return dummy->next;
        
    }


int main(){
    ListNode *head = create();
    printLL(head);
    cout << "delete middle" << endl;
    head = deleteMiddle(head);
    printLL(head);
}