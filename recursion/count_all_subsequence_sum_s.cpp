#include <bits/stdc++.h>
using namespace std;

int print(int i, int s, int arr[], int n, int sum){

    if(i == n){
        if(s == sum)
            return 1;

            return 0;
    }

    int l = print(i + 1, s + arr[i], arr, n, sum);
    int r = print(i + 1, s, arr, n, sum);

    return l + r;
}

int main(){
    int arr[] = { 1,2,1,1,1,2};
    int n = 6;
    int sum = 2;
    int s = 0;

    cout << print(0, s, arr, n, sum) << endl;
}