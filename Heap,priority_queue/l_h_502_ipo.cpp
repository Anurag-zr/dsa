#include<bits/stdc++.h>
using namespace std;


    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); // no. of projects
        
        int capacity =w;  // capital capicity to perform project;
        
        vector<pair<int,int>> project;
        for(int i=0;i<n;i++){
            project.push_back({capital[i],profits[i]});
        }
        
        sort(project.begin(),project.end(),[](pair<int,int> a,pair<int,int> b)->bool{
            return a.first<b.first;
        });
            
        
        priority_queue<int> pqPro; //maxHeap
        
        int i=0;
        
        while(k>0){

            while(i<n && project[i].first<=capacity){
                pqPro.push(project[i++].second);
            }
            
            if(!pqPro.empty()){
                capacity+=pqPro.top();
                pqPro.pop();
                k--;
            }
            else break;
        }
        
        return capacity;
    }



int main(){
    /*
    
    Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects,
 you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
    
    
    */

    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    cout << findMaximizedCapital(k, w, profits, capital) << endl;
}