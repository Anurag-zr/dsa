#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a,vector<int> &b){
    return a[1] < b[1];
}

int main(){

    // vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    vector<vector<int>> courses = {{5,5},{4,6},{2,6}};

//     priority_queue<int, vector<int>, greater<int>> min_pq;
//     // unordered_map<int, int> umap;
//     multimap<int,int> mmap;

//     for (int i = 0; i < courses.size(); i++)
//     {

//         min_pq.push(courses[i][1]);          // last days of courses
//         // umap[courses[i][1]] = courses[i][0]; // courses duaration and courses
//         mmap.insert(make_pair(courses[i][1], courses[i][0]));
//     }      

//         int count=0;
//         int durationSum=0;
//         int lastday =0;
//         while(!min_pq.empty()){
//             lastday = min_pq.top();
            
//             // if(durationSum+umap[min_pq.top()]<=lastday){
//             //     durationSum+=umap[min_pq.top()];
//             //     count++;
//             // }
            
//             // min_pq.pop();

//             auto it = mmap.find(lastday);
//             for (int i = 0; i < mmap.count(lastday);i++){
//                   if(durationSum + it->second <= lastday){
//                     durationSum += it->second;
//                     count++;
//                   }

//                   min_pq.pop();
//                   ++it;
//             }
//         }

//         cout << count << endl;


//         // for(auto it:mmap){
//         //     cout << it.first << " " << it.second << endl;
//         // }

//         // cout << mmap.lower_bound(6)->second << " " << endl; // << endl;
//         // cout << mmap.upper_bound(6)->second << " " << endl;//<< mmap.find(6)->second << endl;

//     //  cout<<mmap.count(68) << endl;
//     //  auto it = mmap.find(6);
//     //  for (int i = 0; i < mmap.count(6);i++){
//     //     cout<<it->second << endl;
//     //     ++it;
//     //  }

    sort(courses.begin(), courses.end(), comp);
    priority_queue<int> maxD;

    int durationsum = 0;

    for (auto i: courses){
        durationsum += i[0];
        maxD.push(i[0]);

        if(durationsum>i[1]){
            durationsum -= maxD.top();
            maxD.pop();
        }
    }

    cout<<maxD.size()<<endl;
}