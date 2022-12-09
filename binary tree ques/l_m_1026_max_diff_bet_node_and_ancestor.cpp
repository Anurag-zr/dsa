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


    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right) return true;
        return false;
    }
    
    pair<int,int> helperFunction(TreeNode* node,int &maxDiff){
     if(node==NULL) return {1e9,-1e9};
     if(isLeaf(node)) return {node->val,node->val};
        
        pair<int,int> lh = helperFunction(node->left,maxDiff);
        pair<int,int> rh = helperFunction(node->right,maxDiff);
        
        if(lh.first!=1e9){ 
            maxDiff = max(maxDiff,abs(node->val - lh.first));
            maxDiff = max(maxDiff,abs(node->val - lh.second));
        }
        if(rh.first!=1e9){
            maxDiff = max(maxDiff,abs(node->val - rh.first));
            maxDiff = max(maxDiff,abs(node->val - rh.second));
        }
        
        int mini = min(node->val,min(lh.first,rh.first));
        int maxi = max(node->val,max(lh.second,rh.second));
        
        return {mini,maxi};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff=INT_MIN;
        helperFunction(root,maxDiff);
        
        return maxDiff;
    }

int main(){
    TreeNode *root = create();

    cout << maxAncestorDiff(root) << endl;
}