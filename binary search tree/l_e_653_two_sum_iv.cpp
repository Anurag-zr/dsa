#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


// Function to create the Binary Tree
struct TreeNode* create()
{
    int data;
    struct TreeNode* tree;
 
    // Dynamically allocating memory
    // for the tree-node
    tree = new TreeNode;
 
    cout << "\nEnter data to be inserted "
         << "or type -1 for no insertion : ";
 
    // Input from the user
    cin >> data;
 
    // Termination Condition
    if (data == -1)
        return nullptr;
 
    // Assign value from user into tree
    tree->val = data;
 
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

    bool find(TreeNode* root,int k,unordered_map<int,TreeNode*> &umap){
        if(root==nullptr) return false;
        if(umap.find(k-root->val)!=umap.end()) return true;
        else{
            umap[root->val]=root;
        }
        
        bool left = find(root->left,k,umap);
        if(left) return true;
        bool right = find(root->right,k,umap);
        if(right) return true;
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        
        unordered_map<int,TreeNode*> umap;
        
        return find(root,k,umap);
    }


    int main(){
        TreeNode* root = create();
        int k = 5;
        cout << findTarget(root, k) << endl;
    }