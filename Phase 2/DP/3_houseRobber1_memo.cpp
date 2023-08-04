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
        if (dp[ind] != -1)
            return dp[ind];
        int left = solve(ind - 1, nums, dp);
        int right = solve(ind - 2, nums, dp) + nums[ind];

        return dp[ind] = max(left, right);
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums.size() - 1, nums, dp);
    }
};