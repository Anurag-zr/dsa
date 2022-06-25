#include <bits/stdc++.h>
using namespace std;

//sliding window approach approach
// time complexity O(n) 
//this approach don't work for negative no.

// int largestSubarray(vector<int> &nums,int k){
//     int maxi = INT_MIN;
//     int sum = 0;

//     int i = 0;
//     for (int j = 0;j<nums.size();j++){
//       sum+=nums[j];

//       if(sum==k){
//           maxi = max(maxi, j - i + 1);
//       }
//       else if(sum>k){
//         while(sum>k){
//             sum = sum - nums[i];
//             i++;
//         }
//          if(sum == k){
//               maxi = max(maxi, j-i+1);
//         }
//       }

//     }

//     return maxi;
// }

// C++ implementation to find the length
// of longest subarray having sum k
#include <bits/stdc++.h>
using namespace std;

// function to find the length of longest
// subarray having sum k
int lenOfLongSubarr(int arr[],
					int n,
					int k)
{

	// unordered_map 'um' implemented
	// as hash table
	unordered_map<int, int> um;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'
		if (sum == k)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'um'
    //if sum not found in map
		if (um.find(sum) == um.end()){
			um[sum] = i;
      cout << "um : key:" << sum << " value: " << i << endl;
    }
  

		// check if 'sum-k' is present in 'um'
		// or not
    //if sum-k found in map
		if (um.find(sum - k) != um.end()) {
      cout << "sum - k: " << sum - k << "value: " << um[sum - k] << endl;
      cout << " i: " << i << endl;
      // update maxLength
			if (maxLen < (i - um[sum - k]))
				maxLen = i - um[sum - k];
		}
	}

	// required maximum length
	return maxLen;
}

// Driver Code
int main()
{
	int arr[] = {-5,8,-14,2,4,12};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = -8;
	cout << "Length = "
		<< lenOfLongSubarr(arr, n, k);
	return 0;
}


// int main(){
//     // vector<int> nums = {4, 1, 1, 1, 2, 3, 5};
//     // vector<int> nums = {1,2,3,7,5};
//     vector<int> nums = {1,1,1,4};
//     int k = 4;

//     cout << largestSubarray(nums, k) << endl;
// }