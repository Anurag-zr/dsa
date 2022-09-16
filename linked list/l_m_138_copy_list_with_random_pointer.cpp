#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int _val) {
        data = _val;
        next = NULL;
        random = NULL;
    }
};


//brute force... extra space
    Node* copyRandomListBrute(Node* head) {
        if(head==NULL) return head;
        
        //brute force;
        
        unordered_map<Node*,Node*> umap;
        
        Node* cur = head;
        while(cur!=NULL){
            umap[cur] = new Node(cur->data);
            cur=cur->next;
        }
        
        cur = head;
        
        while(cur!=NULL){
            umap[cur]->next = umap[cur->next];
            umap[cur]->random = umap[cur->random];
            cur= cur->next;
        }
        
        return umap[head];
    }


    //optima approach...without extra space
    //TC-O(3n)  SC:O(1)

        Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        Node* itr = head;
        
        while(itr!=NULL){
            Node* newNode = new Node(itr->data);
            newNode->next = itr->next;
            itr->next = newNode;
            itr=itr->next->next;
        }
        
        itr = head;
        
        while(itr!=NULL){
           if(itr->random!=NULL) itr->next->random = itr->random->next;
            else itr->next->random = itr->random;
            itr=itr->next->next;
        }
        
        Node* newl = head->next;
        Node* newHead = newl;
        Node* oldl = head;
        
        while(newl->next!=NULL){
            oldl->next = newl->next;
            newl->next = oldl->next->next;
            oldl=oldl->next;
            newl=newl->next;
        }
        
        oldl->next = newl->next;
        
        return newHead;
    }



int main(){
    // create List Node* head = create();

    // Node* new head = copyRandomList(head);
}