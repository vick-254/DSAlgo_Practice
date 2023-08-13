#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return n * price[0];

    if (n == 0)
        return 0;
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int nottake = solve(ind - 1, n, price, dp);
    int take = INT_MIN;
    if (ind + 1 <= n)
        take = solve(ind, n - ind - 1, price, dp) + price[ind];

    return dp[ind][n] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
    return solve(price.size() - 1, n, price, dp);
}
