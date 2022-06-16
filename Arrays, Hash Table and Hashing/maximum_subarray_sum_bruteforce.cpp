 /*  
   here Time complexity is n^3

 better optimal solution is given kadane's algorithm in linear
 complexity O(n) 
   */

  #include <bits/stdc++.h>
  using namespace std;


//  O(n^3) complexity

//   int maxSubArray(vector<int> &nums){
//       int maxi = nums[0];
//       int sum = 0;

//       for (int i = 0;i<nums.size();i++){  
//           for (int j = i;j<nums.size();j++){
//               for (int k = i; k <= j;k++){
//                   sum += nums[k];
//               }

//               maxi= max(maxi,sum);
//             //   cout <<"maxi :"<<maxi<<" sum: "<<sum<<" "<< endl;
//               sum = 0;
//           }
//       }

//       return maxi;
//   }


//O(n^2) complexity

int maxSubArray(vector<int> &nums){
    int sum = 0;
    int maxi = nums[0];
    for (int i = 0;i<nums.size(); i++){
        sum = 0;
        for (int j = i;j<nums.size(); j++){
           sum+=nums[j];
           maxi = max(maxi, sum);
           cout << "maxi: " << maxi << " sums:" << sum << endl;
        }
    }

    return maxi;
}

  int main(){
      vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

      cout << maxSubArray(nums) << endl;
  }