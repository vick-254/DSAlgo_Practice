#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (W >= wt[ind])
                return val[ind];
            else
                return 0;
        }
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int nottake = solve(ind - 1, W, val, wt, dp);
        ;
        int take = INT_MIN;

        if (wt[ind] <= W)
        {
            take = solve(ind - 1, W - wt[ind], val, wt, dp) + val[ind];
        }

        return dp[ind][W] = max(take, nottake);
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(n - 1, W, val, wt, dp);
    }
};