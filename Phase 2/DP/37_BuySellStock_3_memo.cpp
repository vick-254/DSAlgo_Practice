#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int ind, int cap, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (ind == prices.size() || cap == 0)
            return 0;

        if (dp[ind][cap][buy] != -1)
            return dp[ind][cap][buy];
        if (buy == 1)
        {
            return dp[ind][cap][buy] = max(-prices[ind] + solve(ind + 1, cap, 0, prices, dp), solve(ind + 1, cap, 1, prices, dp));
        }
        else
        {
            return dp[ind][cap][buy] = max(prices[ind] + solve(ind + 1, cap - 1, 1, prices, dp), solve(ind + 1, cap, 0, prices, dp));
        }
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0, 2, 1, prices, dp);
    }
};