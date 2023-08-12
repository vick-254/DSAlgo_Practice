#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int ind, int target, vector<vector<int>> &dp, vector<int> &arr)
    {
        if (ind == 0)
            return arr[ind] == target;
        if (target == 0)
            return true;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool nottake = solve(ind - 1, target, dp, arr);
        bool take = false;
        if (target >= arr[ind])
            take = solve(ind - 1, target - arr[ind], dp, arr);

        return dp[ind][target] = take || nottake;
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(arr.size() - 1, sum, dp, arr);
    }
};