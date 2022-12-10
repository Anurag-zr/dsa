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

    void calcTotalSum(TreeNode* node,long long &totalSum){
        if(node==NULL) return;
        totalSum+=node->val;
        calcTotalSum(node->left,totalSum);
        calcTotalSum(node->right,totalSum);
    }
    
    int helper(TreeNode* node,long long &totalSum,long long &maxiProduct){
        if(node==NULL) return 0;
        
        int lh = helper(node->left,totalSum,maxiProduct);
        int rh = helper(node->right,totalSum, maxiProduct);
        
        maxiProduct = max(maxiProduct,lh*(totalSum-lh));
        maxiProduct = max(maxiProduct,rh*(totalSum-rh));
        
        // cout<<node->val<<" "<<totalSum<<" "<<lh<<" "<<rh<<" "<<maxiProduct<<endl;
        
        return node->val+lh+rh;
    }
    
    int maxProduct(TreeNode* root) {
        long long totalSum =0;
        long long maxiProduct = INT_MIN;
        calcTotalSum(root,totalSum);
        helper(root,totalSum,maxiProduct);
        
        return maxiProduct % (int)(1e9 +7);
    }


int main(){
    TreeNode *root = create();
    cout << maxProduct(root) << endl;
}