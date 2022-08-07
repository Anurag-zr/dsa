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


    TreeNode* create(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inMap){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = create(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        
        root->right = create(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root =      create(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        
        return root;
    }
    
    




    void postorder(TreeNode* root){

        if(root == nullptr)
            return;

       
        postorder(root->left);
        postorder(root->right);
         cout << root->val << " ";
    }




    int main(){
        vector<int> inorder = {9, 3, 15, 20, 7};
        vector<int> preorder = {3, 9, 20, 15, 7};

        TreeNode *root = buildTree(inorder, preorder);

        cout << "postorder traversal: in reverse" << endl;

        postorder(root);
    }