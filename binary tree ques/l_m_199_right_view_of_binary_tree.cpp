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


    void reversePreorder(TreeNode* node,int level,vector<int> &ans){
        if(node == NULL) return;
        
        if(level == ans.size()) ans.push_back(node->val);
        reversePreorder(node->right,level+1,ans);
        reversePreorder(node->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        reversePreorder(root,0,ans);
        return ans;
    }


    void preorder(TreeNode* node,int level,vector<int> &ans){
        if(node == NULL) return;
        
        if(level == ans.size()) ans.push_back(node->val);
        preorder(node->left,level+1,ans);
        preorder(node->right,level+1,ans);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        preorder(root,0,ans);
        return ans;
    }

int main(){
    TreeNode* root = create();
    cout << "right side view" << endl;
    vector<int> ans = rightSideView(root);
    for(auto i:ans)
        cout << i << " ";

    ans.clear();

    cout << " \nleft side view " << endl;
     ans = leftSideView(root);
     for(auto i:ans)
        cout << i << " ";
}