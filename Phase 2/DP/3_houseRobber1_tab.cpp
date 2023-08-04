#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind == 0)
            return nums[ind];
        if (ind == 1)
            return max(nums[ind], nums[ind - 1]);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i <= ind; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[ind];
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums.size() - 1, nums, dp);
    }
};