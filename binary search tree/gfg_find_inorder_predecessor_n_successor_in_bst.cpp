#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(){
   Node* node = new Node();
   int data;

   cout << "\nenter data to be inserted or "
        <<"press -1 for no insertion : ";
   cin >> data;

   if(data == -1)
       return nullptr;

   node->data = data;

   cout << "enter left child of: " << data ;
   node->left = create();

   cout << "enter right child of: " << data;
   node->right = create();

   return node;
}

void find(Node* root,Node * &pre,Node* &suc,int key){
    if(root == NULL) return;
    
    if(key<root->data){
        suc = root;
        find(root->left,pre,suc,key);
    }
    else {
        find(root->right,pre,suc,key);
    }
    
    
    if(key>root->data){
        pre= root;
        find(root->right,pre,suc,key);
    }
    else {
        find(root->left,pre,suc,key);
    }

}


int main(){
    Node* root = create();
    int key = 2;

    cout << "find inorder precedessor n successor: " << endl;

    Node* pre=NULL;
    Node *suc = NULL;

    find(root, pre, suc, key);

    cout << pre->data << endl;
    cout<<suc->data << endl;
}

