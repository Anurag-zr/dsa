#include<bits/stdc++.h>
using namespace std;

    void buildGraph(int n,vector<vector<int>> &prerequisites,vector<vector<int>> &adjList){
        int m = prerequisites.size();
        for(int i=0;i<m;i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    }
    
    void findIndegree(int n,vector<vector<int>> &adjList,vector<int> &indegree){
        for(int i=0;i<n;i++){
            for(auto adjNode : adjList[i]){
                indegree[adjNode]++;
            }
        }
    }
    
    bool detectCycleBfs(int n,vector<vector<int>> &adjList,vector<int> &indegree){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int topoSize =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSize++;
            
            for(auto adjNode: adjList[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0) q.push(adjNode);
            }
        }
        
        if(topoSize == n) return false;
        return true ;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
       vector<vector<int>> adjList(n,vector<int>());
        buildGraph(n,prerequisites,adjList);
        
        vector<int> indegree(n,0);
        findIndegree(n,adjList,indegree);
        
        return !detectCycleBfs(n,adjList,indegree);
    }

int main(){
    // Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    // Input: numCourses = 2, prerequisites = [[1,0]]

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << canFinish(numCourses, prerequisites) << endl;
}