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

// naive solution  tc O(n) *O(n)=O(n^2)
    //  int findheight(TreeNode* node){
    //     if(node==nullptr) return 0;
        
    //     int lh = findheight(node->left);
    //     int rh = findheight(node->right);
        
    //     return 1+ max(lh,rh);
    // }
    
    // bool check(TreeNode* node){
    //     if(node == nullptr) return true;
        
    //     int lh = findheight(node->left);
    //     int rh = findheight(node->right);
        
    //     if(abs(lh-rh)>1) return false;
        
    //     if(check(node->left)==false || check(node->right)==false) return false;
        
    //     return true;
    // }        
    
    // bool isBalanced(TreeNode* root) {
    //   return check(root);
    // }


 //optimal solution 
     
     int check(TreeNode* node){
        if(node==nullptr) return 0;
        
        int lh = check(node->left);
        int rh = check(node->right);
        
        if(lh==-1 || rh==-1) return -1;
        
        if(abs(lh-rh)>1) return -1;
        
        return 1+ max(lh,rh);
    }

    bool isBalanced(TreeNode* root){
        if(check(root)==-1) return false;
        return true;
    }
    

int main(){

  TreeNode *root = create();
   
  cout<<isBalanced(root) << endl; 

}