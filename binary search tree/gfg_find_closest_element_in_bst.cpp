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

    int minDiff(Node *root, int k)
    {
        //Your code here
        int ans = abs(root->data - k);
        
        while(root!=NULL){
            if(root->data == k){
                ans =0;
                break;
            }
            
            else if(k<root->data){
                ans = min(ans,abs(root->data -k));
                root= root->left;
            }
            
            else{
                ans = min(ans,abs(root->data -k));
                root= root->right;
            }
        }
        
        return ans;
    }


int  main(){
    Node* root = create();
    cout << minDiff(root, 6) << endl;
}