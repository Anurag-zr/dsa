#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
     TreeNode* left;
     TreeNode* right;

     TreeNode(){

     }

     TreeNode(int data)
     {
         val = data;
         left =nullptr;
         right = nullptr;
    }
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


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        
        if(val<root->val){
            root->left = insertIntoBST(root->left,val);
        }
        else{
            root->right = insertIntoBST(root->right,val);
        }
        
        
        
        return root;
    }

    void preorder(TreeNode* root){
        if(root == NULL)
            return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }



    int main(){
        TreeNode* root = create();
        int p = 15;

        preorder(root);
        cout << endl;

        TreeNode*  newroot = insertIntoBST(root, p);
        preorder(newroot);
    }