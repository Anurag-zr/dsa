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


    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent_track[node->left]  = node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParent(root,parent_track);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        
        int dist =0;
        while(!q.empty()){       
            if(dist++==k) break;
            int size = q.size();
            
            for(int i=0;i<size;i++){
             TreeNode* current = q.front();
             q.pop();
             
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                
                }
                
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;

                }
                
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                    
                }
            }
               
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }


int  main(){
    TreeNode *root = create();
    TreeNode *target = root;
    int k = 1;
    vector<int> ans = distanceK(root, target, k);

    for(auto i:ans){
        cout << i << " ";
    }
}