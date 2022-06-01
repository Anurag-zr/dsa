#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int sum, int target, int arr[], int n, vector<int> &ds, vector<vector<int> > &ans){
  
  if(ind == n){
      if(sum ==target){
          ans.push_back(ds);
      }

      return;
  }

  if(sum<target){
      sum += arr[ind];
      ds.push_back(arr[ind]);
      findCombination(ind, sum, target, arr, n, ds, ans);
      sum -= arr[ind];
      ds.pop_back();
  }

        findCombination(ind+1,sum,target,arr,n, ds,ans);

}

int main(){

    int arr[] = {2, 3, 6, 7};
    int n = 4;
    int target = 7;
    int sum = 0;
    vector<int> ds;
    vector<vector<int>> ans;

    findCombination(0, sum, target, arr, n, ds, ans);

    for(auto it: ans){
        for(auto iit : it){
            cout << iit << " ";
        }
        cout<<endl;
    }
}