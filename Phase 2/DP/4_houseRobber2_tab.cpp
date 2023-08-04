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
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), -1);

        vector<int> temp1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            temp1.push_back(nums[i]);
        }

        int ans1 = solve(temp1.size() - 1, temp1, dp);

        vector<int> dp2(nums.size(), -1);
        vector<int> temp;
        for (int i = 1; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
        }
        int ans2 = solve(temp.size() - 1, temp, dp2);
        return max(ans1, ans2);
    }
};