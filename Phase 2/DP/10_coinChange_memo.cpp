#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[ind] == 0)
                return 1;
            else
                return 0;
        }

        if (amount == 0)
            return 1;
        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int nottake = solve(ind - 1, amount, coins, dp);

        int taker = 0;
        if (amount >= coins[ind])
        {

            taker = solve(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = taker + nottake;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins.size() - 1, amount, coins, dp);
    }
};