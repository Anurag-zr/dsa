#include<bits/stdc++.h>
using namespace std;

    
    bool checkDfs(int node,int paint,vector<int> &color,vector<int> adjList[]){
        color[node]=paint;
        
        for(auto adjNode:adjList[node]){
            cout<<node<<" "<<adjNode<<endl;
            if(color[adjNode]==-1){ //not visited
                if(checkDfs(adjNode,!paint,color,adjList)==false) return false;
            }
            else if(color[adjNode]==color[node]){
                cout<<adjNode<<" "<<node<<" "<<false<<endl;
                return false;
            }
        }
        
        return true;
    }
    
    bool checkBfs(int start,int paint,vector<int> &color,vector<int> adjList[]){
        color[start]=paint;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adjList[node]){
                // cout<<adjNode<<" "<<node<<" "<<color[adjNode]<<endl;
                if(color[adjNode]==-1){
                    color[adjNode]=!color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode]==color[node]){
                    // cout<<adjNode<<" "<<node<<" "<<false<<endl;
                    return false;
                }
            }
        }
        
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adjList[n+1];
        for(auto it:dislikes){
            int u= it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> color(n+1,-1); // -1 represent nodes not visited intially
        
        for(int i=1;i<n+1;i++){
            if(color[i]==-1) //not visited
            {
                // if(checkDfs(i,0,color,adjList)==false){
                //  cout<<i<<endl;
                //  return false;
                // }
                
                if(checkBfs(i,0,color,adjList)==false) return false;
                    
            }
        }
        
        return true;
    }


    int main(){
        /*
        Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
        */


       int n=4;
       vector<vector<int>> dislikes = {
           {1, 2}, {1, 3}, {2, 4}};

       cout << possibleBipartition(n, dislikes) << endl;
    }