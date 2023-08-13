#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(price.size(), vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int i = 0; i < price.size(); i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i < price.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int nottake = dp[i - 1][j];
            int take = INT_MIN;
            if (i + 1 <= j)
                take = dp[i][j - i - 1] + price[i];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[price.size() - 1][n];
}
