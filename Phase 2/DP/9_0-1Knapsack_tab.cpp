#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = 0; i <= W; i++)
        {
            if (i >= wt[0])
                dp[0][i] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int nottake = dp[i - 1][j];
                int take = INT_MIN;
                if (wt[i] <= j)
                {
                    take = dp[i - 1][j - wt[i]] + val[i];
                }

                dp[i][j] = max(take, nottake);
            }
        }
        return dp[n - 1][W];
    }
};