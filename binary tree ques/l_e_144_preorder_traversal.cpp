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


//recursive solution
    // void preorder(TreeNode* node, vector<int> &ans){
    //     if(node == nullptr) return;
    //     ans.push_back(node->val);
    //     preorder(node->left,ans);
    //     preorder(node->right,ans);
    // }
        
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root==nullptr) return {};
    //  vector<int> ans;
    //   preorder(root,ans);  
    //  return ans;
    // }


//iterative solution
    vector<int> preorderTraversal(TreeNode* root){
        if(root==nullptr)
            return {};

        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=nullptr) st.push(node->right);
            if(node->left!=nullptr) st.push(node->left);
        }

        return ans;
    }


int main(){

  //construct binary tree :  [3,9,20,null,null,15,7]
  TreeNode *root = create();
  vector<int> ans = preorderTraversal(root);
  
  for(auto i:ans){
      cout << i << " ";
  }
}