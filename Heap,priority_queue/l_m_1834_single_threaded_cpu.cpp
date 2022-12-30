#include<bits/stdc++.h>
using namespace std;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> process;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            process.push_back({tasks[i][0],tasks[i][1],i});
        }
        
        sort(process.begin(),process.end());
        
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int i=0;
        long long curtime =1;
       
                while (i < n || pq.size()) { // stop the loop when we exhausted the input array and the tasks in the heap.
            if (pq.empty()) {
                curtime = max(curtime,(long long) process[i][0]); // nothing in the heap? try updating the current time using the processing time of the next task in array
            }
            while (i < n && curtime >= process[i][0]) { // push all the tasks in the array whose enqueueTime <= currentTime into the heap
                pq.push({process[i][1], process[i][2]});
                ++i;
            }
                    
            int ptime = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            curtime += ptime; // handle this task and increase the current time by the processingTime
            ans.push_back(index);
        }
        
        return ans;
    }


    int main(){
        /*
        Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
        */

        vector<vector<int>> tasks = {
            {1, 2}, {2, 4}, {3, 2}, {4, 1}};

        vector<int> ans = getOrder(tasks);
        for(auto i:ans)
            cout << i << " ";
    }