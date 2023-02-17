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

    void Inorder(TreeNode* root,int &pre,int &mini){
        if(root==nullptr) return;
        
        
        Inorder(root->left,pre,mini);
        
        // cout<<root->val<<" "<<pre<<endl;
        
        mini = min(mini,abs(root->val - pre));
        pre= root->val;
        Inorder(root->right,pre,mini);
    }
    
    int minDiffInBST(TreeNode* root) {
        int pre = 1e9;
        int ans=1e9;
        Inorder(root,pre,ans);
        return ans;
    }

int main(){
    TreeNode *root = create();
    cout << minDiffInBST(root) << endl;
}