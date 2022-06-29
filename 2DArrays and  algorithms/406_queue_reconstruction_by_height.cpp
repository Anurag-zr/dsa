#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a,vector<int> &b){
    if(a[0]==b[0]){
        return a[1] < b[1];
    }

    return a[0] > b[0];
}

int main(){
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    int n = people.size();

    sort(people.begin(), people.end(), comp);

    vector<vector<int>> ans;

    for (int i = 0; i < n;i++)
    {
        int idx = people[i][1];
        ans.insert(ans.begin() + idx, people[i]);
    }

    for(auto it: ans){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}