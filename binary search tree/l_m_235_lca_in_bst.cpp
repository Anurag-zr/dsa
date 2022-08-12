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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root ==q) return root;
        
        if(p->val<root->val && q->val<root->val){
          TreeNode* left = lowestCommonAncestor(root->left,p,q);
            return left;
        }
        else if(p->val>root->val && q->val>root->val){
          TreeNode* right = lowestCommonAncestor(root->right,p,q);
            return right;
        }
        
        else return root;
    }


    int main(){
        TreeNode* root = create();
        TreeNode *p = new TreeNode();
        p->val = 10;
        TreeNode *q = new TreeNode();
        q->val = 5;

        cout << lowestCommonAncestor(root, p, q)->val << endl;
    }



