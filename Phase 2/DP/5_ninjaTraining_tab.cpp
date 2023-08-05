#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int i = 1; i <= ind; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    int point = points[i][k] + dp[i - 1][k];
                    dp[i][j] = max(dp[i][j], point);
                }
            }
        }
    }

    return dp[ind][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}