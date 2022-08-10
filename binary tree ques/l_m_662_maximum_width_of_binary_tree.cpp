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

    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        int width=0;
        q.push({root,0});
        while(!q.empty()){
          int size = q.size();
          int first,last;
          int min_ind = q.front().second;
          for(int i=0;i<size;i++){
              int cur_ind = q.front().second - min_ind;
              TreeNode* node = q.front().first;
              q.pop();
              if(i==0) first = cur_ind;
              if(i==size-1) last = cur_ind;
              if(node->left!=nullptr) q.push({node->left,(long long) cur_ind*2+1});
              if(node->right!=nullptr) q.push({node->right,(long long) 2*cur_ind+2});
          }
            
            width = max(width,last-first+1);
        }
        
        return width;
    }

int main(){
    TreeNode* root = create();
    cout<<widthOfBinaryTree(root) << endl;

}