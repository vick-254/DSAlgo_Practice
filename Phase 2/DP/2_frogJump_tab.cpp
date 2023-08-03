#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &heights, vector<int> &dp)
{

    if (ind == 0)
        return 0;
    if (ind == 1)
        return abs(heights[1] - heights[0]);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i <= ind; i++)
    {
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[ind];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
}