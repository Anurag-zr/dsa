#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;


    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};


    TreeNode* create(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,map<int,int> &inMap){
        if(postStart>postEnd || inStart>inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot-inStart;
        
        root->left = create(inorder,inStart,inRoot-1,
                            postorder,postStart,postStart+numsLeft-1,inMap);
        
        root->right = create(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap);
        
        return root;
    }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode* root = create(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
        
        
        return root;
    }
    

    void preorder(TreeNode* node){
        if(node == nullptr) return;

        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }


    int main(){
        vector<int> inorder = {40, 20, 50, 10, 60, 30};
        vector<int> postorder = {40, 50, 20, 60, 30, 10};

        TreeNode* root = buildTree(inorder,postorder);
        preorder(root);
    }
    
