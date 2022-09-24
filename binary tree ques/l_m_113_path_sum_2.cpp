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

    void findPathSum(TreeNode* root,int targetSum,vector<int> &ds,vector<vector<int>> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
                ds.push_back(root->val);
                targetSum-=root->val;
                ans.push_back(ds);
                targetSum+=root->val;
                ds.pop_back();
            }
            
            return;
        }
        
        
            ds.push_back(root->val);
            targetSum-=root->val;
            
            findPathSum(root->left,targetSum,ds,ans);
            findPathSum(root->right,targetSum,ds,ans);
            
            targetSum+=root->val;
            ds.pop_back();
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        findPathSum(root,targetSum,ds,ans);
        
        return ans;
    }


int main(){
    TreeNode* root = create();
    int targetSum = -3;

    vector<vector<int>> ans = pathSum(root, targetSum);

    for(auto it:ans){
        for(auto i:it){
            cout << i << " ";
        }

        cout << endl;
    }
}