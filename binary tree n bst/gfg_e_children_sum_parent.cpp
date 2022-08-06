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

    int checkProperty(Node* node){
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return node->data;
        
        int left = checkProperty(node->left);
        int right = checkProperty(node->right);
        
        if(left==-1 || right == -1) return -1;
        if(node->data == left + right) return node->data;
        else return -1;
    }
    
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(checkProperty(root)>0) return 1;
     else  return 0;
    }


int main(){
    Node *root = create();

    cout << isSumProperty(root) << endl;
}