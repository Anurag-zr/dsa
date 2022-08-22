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


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode *head;
        if(list1->val<=list2->val) head = list1;
        else head = list2;
        
        ListNode *temp1,*temp2;
        temp1 = list1;
        temp2 = list2;
        
        ListNode* ans=new ListNode;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                ans->next=temp1;
                ans=ans->next;
                temp1=temp1->next;
            }
            else{
                ans->next=temp2;
                ans=ans->next;
                temp2=temp2->next;
            }
        }
        
        if(temp1==NULL && temp2!=NULL){
            while(temp2!=NULL){
                ans->next = temp2;
                ans=ans->next;
                temp2=temp2->next;
            }
        }
        
        if(temp2==NULL && temp1!=NULL){
            while(temp1!=NULL){
                ans->next = temp1;
                ans=ans->next;
                temp1 = temp1->next;
            }
        }
        
        return head;
    }


int main(){
    ListNode *list1 = create();
    ListNode *list2 = create();

    cout << "list 1" << endl;
    printLL(list1);
    cout << "list 2" << endl;
    printLL(list2);

    ListNode *listRes = mergeTwoLists(list1, list2);

    cout << "After Merging" << endl;
    printLL(listRes);
}