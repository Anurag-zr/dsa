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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> queue;
        bool leftToRight = true;

        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int> level (size);
            for(int i=0;i<size;i++){
                TreeNode* node = queue.front();
                queue.pop();
                if(node->left!=nullptr) queue.push(node->left);
                if(node->right!=nullptr) queue.push(node->right);

                int index = leftToRight ? i : size - 1 - i;

                level[index] = node->val;
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        
        
        return ans;
    }

int main(){

  //construct binary tree :  [3,9,20,null,null,15,7]
  TreeNode *root = create();

  vector<vector<int>> ans;
  ans = levelOrder(root);

  for(auto it:ans){
    for(auto iit: it){
        cout << iit << " ";
    }
    cout << endl;
  }
}