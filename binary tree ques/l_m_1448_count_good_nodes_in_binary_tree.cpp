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


    void preorder(TreeNode* root,int &ans,int maxi){
      if(root==NULL) return;
        
        if(root->val>=maxi){
            ans++;
            maxi = root->val;
        }
        
        preorder(root->left,ans,maxi);
        preorder(root->right,ans,maxi);
    }
    
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        int ans=0;
        
        preorder(root,ans,maxi);

        return ans;
    }



int main(){
    TreeNode *root = create();
    cout << goodNodes(root) << endl;
}