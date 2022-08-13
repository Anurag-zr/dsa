#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left, *right;


    TreeNode(int data){
        val = data;
    }
};


    
    TreeNode* buildTree(vector<int> &pre,int &ind,int bound){
        if(ind>=pre.size() || pre[ind]>bound) return nullptr;
        
        TreeNode* root = new TreeNode(pre[ind]);
        ind++;
        root->left = buildTree(pre,ind,root->val);
        root->right = buildTree(pre,ind,bound);
        
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind =0;
        return buildTree(preorder,ind,INT_MAX);
    }


    void inorder(TreeNode* root){
        if(root==nullptr)
            return;

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }


    int main(){
        vector<int> pre = {8, 5, 1, 7, 10, 12};
        TreeNode *root = bstFromPreorder(pre);

        inorder(root);
    }