#include <bits/stdc++.h>
using namespace std;


//recursive solution 
//TLE for large values 
//n=100 time required = 10^30s/60*60*24*365  years required

// long long fib(int n){
//     if(n<=1)
//         return n;

//     return fib(n - 1) + fib(n - 2);
// }


//memoization solution: 
//tc:O(n) sc:O(n)+O(n)(stack space + dp array space)

// long long fib(int n,vector<long long> &dp){
//    if(n<=1)
//        return n;
    
//     if(dp[n]!=-1) return dp[n];

//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }

// tabulation solution: bottom up solution
// tc: O(n) sc:O(n)

long long fib(int n,vector<long long> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

//space optimization

long long fib(int n){
    long long prev1 = 1;
    long long prev2 = 0;
    long long fib;
    for (int i= 2; i <= n;i++){
        fib= prev1 +prev2;
        prev2 = prev1;
        prev1 = fib;
    }

    return fib;
}

int main(){
    int n = 100;
    vector<long long> dp(n + 1, -1);
    cout << fib(90,dp) << endl;

    for(auto it:dp){
        cout<<it<<endl;
    }
}