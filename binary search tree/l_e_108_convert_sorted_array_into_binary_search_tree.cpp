#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left, *right;


    TreeNode(int data){
        val = data;
    }
};

    TreeNode* func(int start,int end,vector<int> &nums){
        if(start>end) return nullptr;
        
        int mid = start + (end-start) /2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = func(start,mid-1,nums);
        root->right = func(mid+1,end,nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(0,nums.size()-1,nums);
    }



    void preorder(TreeNode* root){
      if(root ==nullptr)
          return;

      cout << root->val<<" ";
      preorder(root->left);
      preorder(root->right);
    }
    

int main(){
    vector<int> nums = {-10, -3, 0, 5, 3};
    TreeNode *root = sortedArrayToBST(nums);
    preorder(root);
}