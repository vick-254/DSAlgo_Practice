#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        int n = prices.size();
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {

                int profit = 0;
                if (j == 1)
                {

                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }

                else
                {

                    profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};