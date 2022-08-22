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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode *dummy = new ListNode;
    ListNode *temp = dummy;
    int carry = 0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum = 0;
        if(l1!=NULL){
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2!=NULL){
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        ListNode *node = new ListNode(sum % 10);
        carry = sum / 10;
        temp->next = node;
        temp = temp->next;
    }

    ListNode *head = dummy->next;
    delete (dummy);
    return head;
}


int main(){
    ListNode* no1 = create();
    ListNode *no2 = create();

    cout << "After Addition: " << endl;
    ListNode *head = addTwoNumbers(no1, no2);
    printLL(head);
}