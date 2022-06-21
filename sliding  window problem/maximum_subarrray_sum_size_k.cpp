#include<bits/stdc++.h>
using namespace std;

//bruteforce
long maximumSubarraySum(vector<int> &arr,int n, int k){
    long maxi = LONG_MIN;
    long sum;

    for (int i = 0;i<=arr.size()-k;i++){
        sum = 0;
        for (int j = i; j < i + k;j++){
            sum += arr[j];
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}


//optimal approach
// long maximumSubarraySum(vector<int> &Arr,int N, int K){
//     long maxi = LONG_MIN;
//         int i=0;
//         int j=0;
//         long sum=0;
//         while(j<N){
//             sum+=Arr[j];
//             if(j-i+1 < K){
//                 j++;
//             }
//             else if(j-i+1 == K){
//              maxi = max(maxi,sum);
//              sum-=Arr[i];
//              i++;
//              j++;
//             }
//         }
        
//         return maxi;
// }

int main(){
    vector<int> nums = {100, 200, 300, 400};
    int window_size = 2;
    cout << maximumSubarraySum(nums, nums.size(), window_size) << endl;
}