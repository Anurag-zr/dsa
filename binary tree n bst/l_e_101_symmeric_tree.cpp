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


    bool isSymmetrical(TreeNode* left,TreeNode* right){
        if(left==nullptr || right==nullptr) return left==right;
        
        if(left->val != right->val) return false;
        
        return isSymmetrical(left->left,right->right) 
            && isSymmetrical(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        
        return isSymmetrical(root->left,root->right);
    }


int main(){
    TreeNode *root = create();
    cout << isSymmetric(root) << endl;
}