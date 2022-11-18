#include<bits/stdc++.h>
using namespace std;

vector<int> calcPrime(int n){
    vector<int> vis(n+1, 0);

    for (int i = 2; i <= n; i++){
        if(!vis[i]){
            for (int j = i * i; j <= n;j+=i){
                vis[j] = 1;
            }
        }
    }

    vector<int> prime;
    for (int i = 2; i <= n;i++){
        if(!vis[i]) prime.push_back(i);
    }

    return prime;
}


int main(){
    int n;
    cout << "enter n under which you want to calc all prime number: " << endl;
    cin >> n;

    vector<int> allPrime = calcPrime(n);

    for(auto prime : allPrime){
        cout << prime << " ";
    }
}