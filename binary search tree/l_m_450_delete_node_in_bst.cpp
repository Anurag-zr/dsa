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


    TreeNode* findMax(TreeNode *node){
        if(node->right == NULL){
            return node;
        }
        
        return findMax(node->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left ==NULL) return root->right;
            if(root->right == NULL) return root->left;
            else{
                TreeNode* maxLeft = findMax(root->left);
                root->val = maxLeft->val;
                root->left = deleteNode(root->left,root->val);
                return root;
            }
        }
        
        if(key<root->val){
           root->left = deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        
        
        return root;
    }


    void preorder(TreeNode *root){
        if(root==NULL) return;

        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    int main(){
        TreeNode* root = create();
        int k = 3;
        root = deleteNode(root, k);
        preorder(root);
    }