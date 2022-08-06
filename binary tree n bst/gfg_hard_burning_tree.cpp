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

   Node* findRef(Node* node, int &target){
       if(node == nullptr) return nullptr;
       if(node->data == target ) return node;
       
       Node* left = findRef(node->left,target);
       Node* right = findRef(node->right,target);
       
       if(left!=nullptr) return left;
       else return right;
   }
   
   void mark_parent ( Node* root,unordered_map<Node*,Node*> &parent_track){
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           Node* node = q.front();
           q.pop();
           
           if(node->left){
               parent_track[node->left] = node;
                q.push(node->left);
               
           }
           
           if(node->right){
               parent_track[node->right] = node;
                q.push(node->right);
           }
       }
   }
   
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        //find reference of target
        Node* ref_target = findRef(root, target);
        unordered_map<Node* ,Node* > parent_track;
        
        // marking parent for every node;
        mark_parent(root,parent_track);
        
        
        //calculating burning time
        int burnTime =0;
        queue<Node*> q;
        unordered_map<Node*,bool> visited;
        
        q.push(ref_target);
        visited[ref_target]=true;
        
        while(!q.empty()){
            int size = q.size();
            int flag =0;
            for(int i=0;i<size;i++){
              Node* cur = q.front();
              q.pop();
                
                if(cur->left && !visited[cur->left]){
                    flag =1;
                    q.push(cur->left);
                    visited[cur->left]=true;
                }
                if(cur->right && !visited[cur->right]){
                    flag=1;
                    q.push(cur->right);
                    visited[cur->right]=true;
                }
                if(parent_track[cur] && !visited[parent_track[cur]]){
                    flag=1;
                    q.push(parent_track[cur]);
                    visited[parent_track[cur]]= true;
                }
                
            }
            
            if(flag) burnTime++;
        }
      
        
       return burnTime;
    }


int main(){

    Node *root = create();
    int target = 2;

    cout<<minTime(root, target)<<endl;
}