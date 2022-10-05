#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(){
        val = 0;
    }

    TreeNode(int _val){
        val = _val;
        left = NULL;
        right = NULL;
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

    TreeNode* addRow(int i,TreeNode* root,int &val,int &depth){
        if(root==NULL) return NULL;
        if(i+1==depth){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
            
            return root;
        }
        
        
        addRow(i+1,root->left,val,depth);
        addRow(i+1,root->right,val,depth);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        return  addRow(1,root,val,depth);
    }

    void preorder(TreeNode* root){
        if(root == NULL) return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }


int main(){
    TreeNode *root = create();
    int val = 1;
    int depth = 2;

    root = addRow(1,root,val,depth);

    preorder(root);


}
