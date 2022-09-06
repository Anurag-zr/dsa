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

void preorder(TreeNode* root){
    if(root==NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}


    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(root->left || root->right || root->val==1) return root;
        
        return nullptr;
    }




int main(){
    TreeNode *root = create();
    preorder(root);
    cout << "\npruned tree: " << endl;
    root = pruneTree(root);

    preorder(root);
}