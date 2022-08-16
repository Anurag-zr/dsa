#include<bits/stdc++.h>
using namespace std;

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

class BSTIterator {
private: 
    stack<TreeNode*> mystack;
    
    void pushAll(TreeNode* node){
        while(node!=nullptr){
            mystack.push(node);
            node=node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = mystack.top();
        mystack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
};


int main(){
    TreeNode *root = create();
    BSTIterator* itr = new BSTIterator(root);

    while(itr->hasNext()){
        cout << itr->next() << " ";
    }
}