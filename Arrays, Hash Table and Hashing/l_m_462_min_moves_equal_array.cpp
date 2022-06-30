
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


    int main(){
        vector<int> nums ={-2,-1,0,1,2,3};
        cout << "ans :" << minMoves(nums) << endl;
        for(auto i:nums){
            cout << i
                 << " ";
        }
    }