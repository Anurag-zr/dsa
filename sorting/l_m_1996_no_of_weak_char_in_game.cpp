#include<bits/stdc++.h>
using namespace std;


    
//    static bool comp(vector<int> &a,vector<int> &b){
//         if(a[0]==b[0]){
//             return a[1]>=b[1];
//         }
//          return a[0]>b[0];
//     }
    
    //  TLE APPROCH
    // int numberOfWeakCharacters(vector<vector<int>>& properties) {
    //     sort(properties.begin(),properties.end(),comp);
        
    //     int n=properties.size();
        
    //     int weakChar=0;
        
    //     unordered_map<int,int> map;
        
       
        
    //     for(int i=0;i<n-1;i++){
    //      int attack = properties[i][0];
    //      int defence = properties[i][1];
    //         for(int j=i+1;j<n;j++){
    //             if(properties[j][0]<attack && properties[j][1]<defence && map.find(j)==map.end()){
    //                 weakChar++;
    //                 map[j]++;
    //             }
                
    //         }
            
            
    //     }
        
    //     return weakChar;
    // }


    //optimal solution

    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
         return a[0]>b[0];
    }


        int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        
        int n = properties.size();
        
        int maxdefence = INT_MIN;
        int weakChar=0;
        
        for(int i=0;i<n;i++){
            if(properties[i][1]<maxdefence) weakChar++;
            maxdefence = max(maxdefence,properties[i][1]);
        }
        
        return weakChar;
    }


int main(){
    // [[7,7],[1,2],[9,7],[7,3],[3,10],[9,8],[8,10],[4,3],[1,5],[1,5]]

    vector < vector<int>> properties = {
        {7, 7},
        {1, 2},
        {9, 7},
        {7, 3},
        {3, 10},
        {9, 8},
        {8, 10},
        {4, 3},
        {1, 5},
        {1, 5}};

    cout << numberOfWeakCharacters(properties) << endl;
}