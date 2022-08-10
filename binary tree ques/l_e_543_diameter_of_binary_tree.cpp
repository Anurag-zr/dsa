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

    int findDia(TreeNode* node,int &maxi){
        if(node==nullptr) return 0;
        
        int lh = findDia(node->left,maxi);
        int rh = findDia(node->right,maxi);
        
        maxi = max(maxi,lh+rh);
        
        return 1+ max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        findDia(root,maxi); 
        return maxi;
    }


int main(){
    TreeNode *root = create();
    cout << diameterOfBinaryTree(root) << endl;
}