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
};


    bool hasPathSum(TreeNode* root, int target) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            
            if((target-root->val)==0) return true;
            
            else false;
        }
        
        
        if(hasPathSum(root->left,target-root->val)==true) return true;
        if(hasPathSum(root->right,target-root->val)==true) return true;
        
        
        return false;
    }


int main(){
    TreeNode* root = create();
    int target = -5;
    cout << hasPathSum(root, target);
}