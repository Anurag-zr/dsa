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


//recursive solution
    // void inorder(TreeNode* node,vector<int> &ans){
    //     if(node == nullptr) return;
    //     inorder(node->left,ans);
    //     ans.push_back(node->val);
    //     inorder(node->right,ans);
    // }
    
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(root==nullptr) return {};
    //     vector<int> ans;
    //     inorder(root,ans);
    //     return ans;
    // }

//iterative solution
     vector<int> inorderTraversal(TreeNode* root){
        if(root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while(true){
            if(node!=nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()==true)
                    break;

                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }


        return ans;
     }

int main(){

  //construct binary tree :  [3,9,20,null,null,15,7]
  TreeNode *root = create();
  vector<int> ans = inorderTraversal(root);
  
  for(auto i:ans){
      cout << i << " ";
  }
}