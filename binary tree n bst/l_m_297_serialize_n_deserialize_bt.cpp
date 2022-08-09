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


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node =  q.front();
            q.pop();
            
            if(node!=nullptr){
            ans+=to_string(node->val);
            ans+=",";
            }
            else{
                ans+="N,";
            }
            
            if(node!=nullptr){
                q.push(node->left);
                q.push(node->right);
            }
            
 
            
        }
        
        return ans;
    }


        // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;

        getline(s, str, ',');
        if(str=="N")
            return nullptr;

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode();
        root->val = stoi(str);
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node= q.front();
            q.pop();

            getline(s, str, ',');
            if(str=="N") node->left = nullptr;
            else{
                TreeNode* leftNode = new TreeNode();
                leftNode->val = stoi(str);
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str=="N") node->right = nullptr;
            else{
                TreeNode* rightNode = new TreeNode();
                rightNode->val =stoi(str);
                node->right = rightNode;
                q.push(rightNode);
            }
            
        }
        
        return root;
    }



int main(){
    TreeNode *root = create();
     
    string data = serialize(root);
    cout << data << endl;

    // string data = "1,2,3,N,N,N,N,";
    cout << deserialize(data)->val << endl;
}