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


    ListNode* reverse(ListNode* first,ListNode* last){
        ListNode *prev = last;
        ListNode *cur = first;
        ListNode *temp;

        while(cur!=last){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;

        for (int i = 0; i < k;i++){
            if(node==NULL)
                return head; // too short list k group

                node=node->next;
        }

        ListNode *newHead = reverse(head, node); // first and last till then we have to reverse
        head->next = reverseKGroup(head->next, k);

        return newHead;
    }



int main(){
    ListNode *head = create();
    int k = 3;

    printLL(head);

    head = reverseKGroup(head, k);

    cout << "After revesing nodes in k group: " << endl;
    
    printLL(head);
}