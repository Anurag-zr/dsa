#include<bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


// Function to create the Binary Tree
struct Node* create()
{
    int data;
    struct Node* tree;
 
    // Dynamically allocating memory
    // for the tree-node
    tree = new Node;
 
    cout << "\nEnter data to be inserted "
         << "or type -1 for no insertion : ";
 
    // Input from the user
    cin >> data;
 
    // Termination Condition
    if (data == -1)
        return nullptr;
 
    // Assign value from user into tree
    tree->data = data;
 
    // Recursively Call to create the
    // left and the right sub tree
    cout << "Enter left child of : "
         << data;
    tree->left = create();
 
    cout << "Enter right child of : "
         << data;
    tree->right = create();
 
    // Return the created Tree
    return tree;
}

    bool isLeaf(Node* node){
        if(node->left == nullptr && node->right == nullptr) return true;
        else return false;
    }
    
    void addLeftBoundary(Node* root,vector<int> &ans){
        Node* cur = root->left;
        while(cur!=nullptr){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left!=nullptr) cur=cur->left;
            else cur= cur->right;
        }
    }
    
    void addLeaves(Node* node,vector<int> &ans){
        if(isLeaf(node)) {
            ans.push_back(node->data);
            return;
        }
        
        if(node->left!=nullptr) addLeaves(node->left,ans);
        if(node->right!=nullptr) addLeaves(node->right,ans);
    }
    
    void addRightBoundary(Node* root,vector<int> &ans){
        vector<int> temp;
       Node*  cur = root->right;
        while(cur!=nullptr){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right!=nullptr) cur=cur->right;
            else
              cur= cur->left;
        }
        
        int size = temp.size();
        for(int i = size-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==nullptr) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        
        return ans;
        
    }


int main(){
    Node *root = create();
    vector<int> ans = boundary(root);

    for(auto it: ans){
        cout << it << " ";
    }
}