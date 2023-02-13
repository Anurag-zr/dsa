#include<bits/stdc++.h>
using namespace std;

    int minMovesToMakePalindrome(string s) {
       
        vector<char> arr;
        for(auto c: s) arr.push_back(c);
        
        int i=0;
        int j= arr.size()-1;
        // cout<<j<<endl;
        int minDel =0;
        int oddInd = -1;

        while(i<j){
            
            // cout<<arr[i]<<arr[j]<<endl;
            
            if(arr[i]==arr[j]){
                i++;
                j--;
                continue;
            }
            
            bool pairFound = false;
            int k;
            for(k =i;k<j;k++){
                if(arr[k]==arr[j]){
                    pairFound= true;
                    char temp = arr[k];
                    minDel+=k-i;
                    
                    for(int ptr= k-1;ptr>=i;ptr--){
                        arr[ptr+1]=arr[ptr];
                    }
                    
                    arr[i]= temp;
                    i++; j--;
                    break;
                }
            }

            if(!pairFound){ //for odd length string when corresponding equal char not found
                oddInd = j;
                int midInd = i + (j - i) / 2;
                char temp = arr[k];
                minDel += k - midInd;

                j--;

                //                     for(int ptr= k-1;ptr>=midInd;ptr--){
                //                         arr[ptr+1]=arr[ptr];
                //                     }

                //                 arr[midInd] = temp;
                
            }
            
            
        }


        if(oddInd!=-1){
            char temp = arr[oddInd];

            for(int ptr= oddInd-1;ptr>=arr.size()/2;ptr--){
               arr[ptr+1]=arr[ptr];
            }

              arr[arr.size()/2]= temp;

        }

        for (auto c: arr)
              cout << c << "";

        cout << endl;

        return minDel;
    }

int main(){
   /* 
   "xvxolsnxznojrziiiknlvxheddvzhzzrjinzvevsjzgzccgkv"
   274
   */

        string s = "xvxolsnxznojrziiiknlvxheddvzhzzrjinzvevsjzgzccgkv";
        cout << minMovesToMakePalindrome(s) << endl;
}