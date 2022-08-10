#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(){
   Node* node = new Node();
   int data;

   cout << "\nenter data to be inserted or "
        <<"press -1 for no insertion : ";
   cin >> data;

   if(data == -1)
       return nullptr;

   node->data = data;

   cout << "enter left child of: " << data ;
   node->left = create();

   cout << "enter right child of: " << data;
   node->right = create();

   return node;
}

    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            Node* node = pr.first;
            int v_line = pr.second;
            
            if(mp.find(v_line)==mp.end()){ mp[v_line] = node->data;}
            else{
                mp.erase(v_line);
                mp[v_line]=node->data;
            }
            
            if(node->left!=nullptr) q.push({node->left,v_line-1});
            if(node->right!=nullptr) q.push({node->right,v_line+1});
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }



int main(){
    Node *root = create();
    vector<int> ans = bottomView(root);

    for(auto i:ans){
        cout << i << " ";
    }
}