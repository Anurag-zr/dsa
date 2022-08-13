#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* insertBST(TreeNode* root,int data){
    if(root == nullptr) return new TreeNode(data);

    if(data<root->val) root->left =  insertBST(root->left,data);
    else root->right = insertBST(root->right,data);

    return root;
}



    int kthLargest(TreeNode* root, int &k) {
        if(root==NULL) return INT_MIN;
        int r= kthLargest(root->right,k);
        if(r!=INT_MIN) return r;
        k--;
         if(k==0) return root->val;

        int l=kthLargest(root->left,k);
        
        return l;
    }



    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL) return INT_MAX;
        int l= kthSmallest(root->left,k);
        if(l!=INT_MAX) return l;
        k--;
         if(k==0) return root->val;

        int r=kthSmallest(root->right,k);
        
        return r;
    }


    int main(){
        vector<int> arr = {23, 90, 34, 57, 12, 1};
        TreeNode *root = nullptr;
        for (int i = 0; i < arr.size();i++){
                root = insertBST(root, arr[i]);
        }
        int k = 3;
        cout << "\nkth smallest:";
        cout << kthSmallest(root, k) << endl;
        cout << "kth largest:";
        k = 3;
        cout << kthLargest(root, k) << endl;
    }