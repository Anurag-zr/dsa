#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

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

class Solution {
    private:
    TreeNode *prev;
    TreeNode *first;
    TreeNode *mid;
    TreeNode *last;
    
    
    void inorder(TreeNode* node){
        if(node==nullptr) return;
        
        inorder(node->left);
        if(prev!=nullptr && prev->val>node->val){
            if(first==nullptr){//1st violation
                first = prev;
                mid = node;
            }
            else{
                last = node;
            }
        }
        prev=node;
        inorder(node->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
      first=mid=last=prev=nullptr;
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else swap(first->val,mid->val);
    }
};



void inorder(TreeNode* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}



int main(){
    TreeNode *root = create();

    Solution obj;

    obj.recoverTree(root);

    inorder(root);
}