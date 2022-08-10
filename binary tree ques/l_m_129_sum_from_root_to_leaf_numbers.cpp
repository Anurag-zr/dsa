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

 void Path(TreeNode* node,int ds_sum,vector<int> &ans){
     if(node==nullptr) return;
     
     if(node->left==nullptr && node->right == nullptr){ 
        ans.push_back(ds_sum*10+node->val);  
         return;
     }
     
     Path(node->left, ds_sum*10 + (node->val),ans);
     Path(node->right, ds_sum*10 + (node->val),ans);
 }
    
    int sumNumbers(TreeNode* root) {
      int ds_sum=0;
      vector<int> ans;
        Path(root,ds_sum,ans);
        
        int sum=0;
        for(auto i:ans){
            sum+=i;
        }
        
        return sum;
    }



    int main()
    {
        TreeNode* root = create();
        cout << sumNumbers(root) << endl;
    }
