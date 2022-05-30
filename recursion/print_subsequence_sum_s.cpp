#include<bits/stdc++.h>
using namespace std;

void print(int i, vector<int> &ds, int s, int arr[], int n, int sum){
    if (i == n){
        if (s==sum){
            for(auto it:ds){
                cout << it << " ";
            }
            cout<<endl;
        }

        return;
    }

    ds.push_back(arr[i]);
    print(i + 1, ds, s + arr[i], arr, n, sum);
    ds.pop_back();
    print(i + 1, ds, s, arr, n, sum);
}

int main(){
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> ds;
    int sum = 3;
    int s = 0;

    print(0, ds, s, arr, n, sum);
}