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

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    
    int ans= root->data;
    while( root!=NULL){
        if(root->data == input){ 
            ans = root->data;
            break;
        }
        else if(input<root->data){
                ans=root->data;
                root=root->left;
        }
        else{
            root=root->right;
        }
    }
    
    return ans;
}


int main(){
    Node* root= create();
    cout << findCeil(root, 8) << endl;
}