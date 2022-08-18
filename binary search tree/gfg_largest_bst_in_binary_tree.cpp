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


    pair<int,pair<int,int>> largestBstHelper(Node* node){
        if(node==nullptr) return make_pair(0,make_pair(INT_MIN,INT_MAX)); //always satisfy
        
        auto left = largestBstHelper(node->left);
        auto right = largestBstHelper(node->right);
        
        if(left.second.first<node->data && right.second.second>node->data) //it's bst
         return {left.first+right.first+1,{max(right.second.first,node->data),
                                        min(left.second.second,node->data)}};
                                        
        //otherwise return{max_size,{inf,-inf}}
        return {max(left.first,right.first),{INT_MAX,INT_MIN}};
        
    }
    
    int largestBst(Node *root)
    {   
    	//Your code here
    	//pair store <size,<maxNode,minNode>>
    	pair<int,pair<int,int>> ans = largestBstHelper(root);
    	return ans.first;
    }


int main(){
    Node *root = create();

    cout << largestBst(root) << endl;
}