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


//approach 1 : Tc: O(m+n)  sc:O(m) 
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
    //     unordered_map<ListNode*,bool> umap;
    //     ListNode* temp=headA;
    //     while(temp!=NULL){
    //         umap[temp]=true;
    //         temp=temp->next;
    //     }
        
        
    //     temp= headB;
        
    //     while(temp!=NULL){
    //         if(umap.find(temp)!=umap.end()) return temp;
    //         temp=temp->next;
    //     }
        
    //     return NULL;
    // }

//approach 2: o(2m) short and crisp

    ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
        ListNode *dummyA, *dummyB;
        dummyA = headA;
        dummyB = headB;

        while(dummyA!=dummyB){
            dummyA = dummyA == NULL ? headB : dummyA->next;
            dummyB = dummyB == NULL ? headA : dummyB->next;
        }

        return dummyA;
    }


    int main(){
        ListNode* headA = create();
        ListNode *headB = create();

        ListNode *temp = headA;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = headB->next->next;

        printLL(headA);
        printLL(headB);

        ListNode *intersectedNode = getIntersectionNode(headA, headB);

        cout << intersectedNode->val << endl;
    }