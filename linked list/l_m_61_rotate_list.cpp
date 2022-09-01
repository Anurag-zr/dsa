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


    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode *temp = head;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }

        // cout << n << endl;
        k = k % n;

        if(k==0)
            return head;

        temp = head;
        for (int i = 0; i < n - k-1;i++){
            // cout << temp->val << endl;
            temp = temp->next;
        }

        cout << temp->val << endl;

        ListNode *head1 = temp->next;
        temp->next = NULL;

        temp = head1;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = head;
        head = head1;

        return head;
    }



int main(){
    ListNode *head = create();
    printLL(head);
    head = rotateRight(head, 2);
    cout << "After rotation: " << endl;
    printLL(head);
}