#include<bits/stdc++.h>
using namespace std;

// i modified this question instead of picking left or right you can pick any
//  element in num :- you have to maximize the score 
int maximumScore(vector<int> &nums, vector<int> &multipliers)
{
    sort(nums.begin(), nums.end());
    sort(multipliers.begin(), multipliers.end());

    int nStart = 0;
    int nEnd = nums.size() - 1;

    int mStart = 0;
    int mEnd = multipliers.size() - 1;

    unsigned int ans = 0;

    while (nums[nStart] < 0 && multipliers[mStart] < 0)
    {
        ans += nums[nStart] * multipliers[mStart];
        nStart++;
        mStart++;
    }

    while (nums[nEnd] >= 0 && multipliers[mEnd] >= 0)
    {
        ans += nums[nEnd] * multipliers[mEnd];
        nEnd--;
        mEnd--;
    }

    for (int i = mStart; i <= mEnd; i++)
    {
        int optimal;

        if (abs(nums[nStart] <= abs(nums[nEnd])))
        {
            optimal = nums[nStart];
            nStart++;
        }
        else
        {
            optimal = nums[nEnd];
            nEnd--;
        }

        ans += optimal * multipliers[i];
    }

    return ans;
    }


int main(){
    // nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]

    // [555,526,732,182,43,-537,-434,-233,-947,968,-250,-10,470,-867,-809,-987,120,607,-700,25,-349,-657,349,-75,-936,-473,615,691,-261,-517,-867,527,782,939,-465,12,988,-78,-990,504,-358,491,805,756,-218,513,-928,579,678,10]
// [783,911,820,37,466,-251,286,-74,-899,586,792,-643,-969,-267,121,-656,381,871,762,-355,721,753,-521]

    vector<int> nums ={555, 526, 732, 182, 43, -537, -434, -233, -947, 968, -250, -10, 470, -867, -809, -987, 120, 607, -700, 25, -349, -657, 349, -75, -936, -473, 615, 691, -261, -517, -867, 527, 782, 939, -465, 12, 988, -78, -990, 504, -358, 491, 805, 756, -218, 513, -928, 579, 678, 10};

    vector<int> multipliers = {783, 911, 820, 37, 466, -251, 286, -74, -899, 586, 792, -643, -969, -267, 121, -656, 381, 871, 762, -355, 721, 753, -521};

    cout << maximumScore(nums, multipliers) << endl;
}