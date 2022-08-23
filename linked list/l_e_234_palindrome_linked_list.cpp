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


    bool isPalindrome(ListNode* head) {
        string s="";
        string revs="";
            
        ListNode *newHead =NULL;
        ListNode *temp;
        
        while(head!=NULL){   //linked list structure got reversed while executing this code
            temp=head->next;
            s+=(head->val+'0');
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        
        
        //linked list structure again got reversed after following code execution
        //retreving the original linked list structure again.
        head = NULL;  
        while(newHead!=NULL){  
            temp=newHead->next;
            revs+=(newHead->val + '0');
            newHead->next=head;
            head=newHead;
            newHead=temp;
        }
        
        if(s==revs) return true;
        return false;
    }


    int main(){
        ListNode* head = create();
        printLL(head);

        cout << "is Palindrome : " << isPalindrome(head) << endl;

        printLL(head);
    }