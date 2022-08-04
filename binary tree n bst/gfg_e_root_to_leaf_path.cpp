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

 void findPath(Node* node,vector<int> &ds,vector<vector<int>> &ans){
     if(node==nullptr) return;
     
     if(node->left==nullptr && node->right == nullptr){ 
         ds.push_back(node->data);
        ans.push_back(ds);   
        ds.pop_back();
         return;
     }
     
     ds.push_back(node->data);
     findPath(node->left,ds,ans);
     findPath(node->right,ds,ans);
     ds.pop_back();
 }
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>> ans;
    vector<int> ds;
    findPath(root,ds,ans);
    return ans;
}

int main(){
    Node* root = create();
    vector<vector<int>> ans = Paths(root);

    for(auto it:ans){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}