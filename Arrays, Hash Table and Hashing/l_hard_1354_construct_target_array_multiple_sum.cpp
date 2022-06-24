#include<bits/stdc++.h>
using namespace std;


//status : TLE
bool isPossible(vector<int> &target) {
     int n = target.size();
    vector<int> ans(n, 1);

    int sum = n;
    

    sort(target.begin(), target.end());

    for (int i = 0; i < n;){

        if(target[i]==1){
            i++;
            continue;
        }

        if(sum>target[i]){
            return false;
        }

        if(sum == target[i]){
            ans[i] = target[i];
            cout<<ans[i]<<endl;
            sum = 0;
            for (int j = 0; j < n;j++){
                sum += ans[j];
            }
            // cout<<sum<<"sum == trget"<<endl;
                i++;
        }
     
        else{
            if(i==0) ans[i] = sum;
            else
                ans[i - 1] = sum;
            sum = 0;
            for (int j = 0; j < n;j++){
                sum += ans[j];
            }
           
            // cout<<sum<<endl;
        }

        } 

        // for(auto i:ans){
        //     cout << i << " ";
        // }
        // cout << endl;

        return true;
}

int main(){

    vector<int> target = {8,5};
    cout << isPossible(target) << endl;
}
