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


    bool isSame(TreeNode* p,TreeNode* q){
       if(p==nullptr || q==nullptr)  return(p==q);        
        
        bool left = isSame(p->left,q->left);
        bool right = isSame(p->right,q->right);
        
        if(p->val==q->val && left==true && right==true) return true;
        
        return false;
    }


int main(){
    cout <<" create p "<< endl;
    TreeNode *p = create();
    cout << "create q" << endl;
    TreeNode *q= create();

    cout << isSame(p, q) << endl;
}

