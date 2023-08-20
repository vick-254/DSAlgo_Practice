#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int solve(int ind, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
            return 0;
        int maxi = 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy == 1)
        {
            int take = -prices[ind] + solve(ind + 1, 0, prices, dp);
            int nottake = solve(ind + 1, 1, prices, dp);

            maxi = max(take, nottake);
        }

        else
        {
            int take1 = prices[ind] + solve(ind + 1, 1, prices, dp);
            int nottake1 = solve(ind + 1, 0, prices, dp);

            maxi = max(take1, nottake1);
        }

        return dp[ind][buy] = maxi;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};