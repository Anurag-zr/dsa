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



    TreeNode* searchBST(TreeNode* root, int val) {
//      if(root==NULL) return  NULL;
        
//         if(root->val == val) return root;
//         else if(val<root->val){
//          TreeNode* left = searchBST(root->left,val);
//         return left;
//         }
//         else{
//             TreeNode* right = searchBST(root->right,val);
//             return right;
//         }
        
        
        while(root!=NULL  && root->val!=val){
            root= val<root->val?root->left:root->right;
        }
        
        return root;
    }



    int main(){
        TreeNode* root = create();
        int val = 10;

        TreeNode *ans = searchBST(root, val);

        cout << ans->val << endl;
    }