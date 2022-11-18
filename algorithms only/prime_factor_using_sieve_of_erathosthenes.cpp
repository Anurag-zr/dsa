#include<bits/stdc++.h>
using namespace std;

    vector<int> calcPrimeFactor(int n){
        vector<int> spf(n+1,0);
        for(int i=2;i<=n;i++) spf[i]=i;
        
        for(int i=2;i<=n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=n;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
        
        
        vector<int> primeFactor;
        
        while(n!=1){
            primeFactor.push_back(spf[n]);
            n=n/spf[n];
        }
        
        return primeFactor;
    }

int main(){
    cout << "calc prime factor of any number" << endl;
    cout << "enter number: " << endl;
    int n;
    cin >> n;

    vector<int> primeFac = calcPrimeFactor(n);
    cout << "prime factor" << endl;
    for (auto i: primeFac){
        cout << i << " ";
    }
}