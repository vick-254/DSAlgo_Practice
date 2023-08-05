#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (last != i)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[ind][last] != -1)
        return dp[ind][last];

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        int point = 0;
        if (last != i)
            point = points[ind][i] + solve(ind - 1, i, points, dp);
        maxi = max(maxi, point);
    }
    return dp[ind][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}