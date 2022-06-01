#include <bits/stdc++.h>
using namespace std;

void findComb(int ind,int sum, int target,vector<int> &arr, vector<int> &ds,set<vector<int>> &ans){
    if (ind == arr.size()){
        if(sum == target){
            ans.insert(ds);
        }

        return;
    }

    if(sum < target){
        sum += arr[ind];
        ds.push_back(arr[ind]);
        findComb(ind+1,sum,target,arr,ds,ans);
        ds.pop_back();
        sum -= arr[ind];
    }

    findComb(ind + 1, sum, target, arr, ds, ans);
}

int main(){
    vector<int> arr = {10, 1,2,7,6,1,5};
    sort(arr.begin(), arr.end());
    int target = 8;
    int sum = 0;
    vector<vector<int>> f_ans;
    set<vector<int>> ans;
    vector<int> ds;

    findComb(0, sum, target, arr, ds, ans);

   for(auto it:ans){
        f_ans.push_back(it);
    }

    for(auto it:f_ans){
        for(auto it2:it){
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}