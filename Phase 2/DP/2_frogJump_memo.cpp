#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (ind == 1)
        return abs(heights[ind] - heights[ind - 1]);
    if (dp[ind] != -1)
        return dp[ind];
    int left = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
}