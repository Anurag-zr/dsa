
#include <bits/stdc++.h>
using namespace std;

// in one move, you can increment n-1 element by 1
// status TLE for input [1,10000000000000];
// status TLE for input  [1,1,100000000000000];

//TC= ??

int minMoves(vector<int> &nums)
{
    int n = nums.size();
    int moves = 0;
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());
    int flag;

    while (min != max)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (max == nums[i] && flag != 1)
            {
                flag = 1;
                continue;
            }
            nums[i] += 1;
        }
        moves++;
        min = *min_element(nums.begin(), nums.end());
        max = *max_element(nums.begin(), nums.end());
    }

    return moves;
    }

        //By sorting and keeping the value of min element stored, O(NlogN)
    //By traversing for i>0 increment all n-1 element exept cur element upto min, update cur
    //summition of increments in first upto cur;
    //update min
    // int minMoves(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     int totalmoves = 0;
    //     int first = nums[0],cur;
    //     for(int i = 1;i<n;i++){
    //         cur = nums[i] + totalmoves;
    //         totalmoves += cur - first;
    //         first = cur;
    //     }
    //     return totalmoves;
    // }

    // //Optimized approch, using summition O(N)
    // int minMoves(vector<int>& nums) {
    //     int sum=0,num_min=INT_MAX;
    //     for(int a:nums){
    //         sum+=a;
    //         num_min=min(num_min,a);
    //     }
    //     return sum-(num_min*nums.size());
    // }


    int main(){
        vector<int> nums ={-2,-1,0,1,2,3};
        cout << "ans :" << minMoves(nums) << endl;
        for(auto i:nums){
            cout << i
                 << " ";
        }
    }