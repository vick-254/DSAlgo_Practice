#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        int n = coins.size();
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int nottake = dp[i - 1][j];

                int taker = 0;
                if (j >= coins[i])
                {

                    taker = dp[i][j - coins[i]];
                }

                dp[i][j] = taker + nottake;
            }
        }
        return dp[n - 1][amount];
    }
};