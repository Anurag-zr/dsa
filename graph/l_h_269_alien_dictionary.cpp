#include<bits/stdc++.h>
using namespace std;

    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adjList[K];
        vector<int> indegree(K,0);
        for(int i=0;i<N-1;i++){
          string a = dict[i];
          string b = dict[i+1];
          
          for(int j=0;j<min(a.length(),b.length());j++){
              if(a[j]!=b[j]){
                  adjList[a[j]-'a'].push_back(b[j]-'a');
                  indegree[b[j]-'a']++;
                  break;
              }
          }
        }
          
          
          
          queue<int> q;
          for(int i=0;i<K;i++){
              if(indegree[i]==0) q.push(i);
          }
          
          vector<char> order;
          while(!q.empty()){
              int node = q.front();
              q.pop();
              order.push_back(node+'a');

              
              for(auto adjNode: adjList[node]){
                  indegree[adjNode]--;
                  if(indegree[adjNode]==0) q.push(adjNode);
              }
          }
        
        string ans="";
        for(auto it:order){
            // cout<<it<<" ";
            ans+=it;
        }
        return ans;
    }

int main(){
    int N = 5, K = 4;
    string dict[N] = {"baa",
                           "abcd",
                           "abca",
                           "cab",
                           "cad"};

    cout << findOrder(dict, N, K) << endl;
}