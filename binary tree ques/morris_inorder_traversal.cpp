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

    void morrisTraversal(TreeNode* root){
        TreeNode *cur = root;

        while(cur!=nullptr){
            if(cur->left==nullptr){
                cout << cur->val << " ";
                cur = cur->right;
            }
            else{

                TreeNode* temp = cur->left;

                while(temp->right!=nullptr  && temp->right!=cur){
                    temp = temp->right;
                }

                if(temp->right == nullptr){
                    temp->right = cur;
                    cur = cur->left;
                }

                else if (temp->right == cur){
                    temp->right = nullptr;
                    cout << cur->val << " ";
                    cur = cur->right;
                }
            }
        }
    }


// vector < int > morrisTraversal(TreeNode * root) {
//   vector < int > inorder;

//   TreeNode * cur = root;
//   while (cur != NULL) {
//     if (cur -> left == NULL) {
//       inorder.push_back(cur -> val);
//       cur = cur -> right;
//     } else {
//       TreeNode * prev = cur -> left;
//       while (prev -> right != NULL && prev -> right != cur) {
//         prev = prev -> right;
//       }

//       if (prev -> right == NULL) {
//         prev -> right = cur;
//         cur = cur -> left;
//       } else {
//         prev -> right = NULL;
//         inorder.push_back(cur -> val);
//         cur = cur -> right;
//       }
//     }
//   }
//   return inorder;
// }
    

int main(){
   

    TreeNode *root = create();
    cout << "inorder morris traversal" << endl;

    morrisTraversal(root);
    // vector<int> ans = morrisTraversal(root);
    
    // for (auto i:ans){
        // cout << i << " ";
    // }
}