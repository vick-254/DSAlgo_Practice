#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        dp[0][0] = grid[0][0];

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    int up = 85000;
                    int left = 85000;
                    if (i > 0)
                        up = dp[i - 1][j] + grid[i][j];
                    if (j > 0)
                        left = dp[i][j - 1] + grid[i][j];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m][n];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int i = grid.size();
        int j = grid[0].size();

        vector<vector<int>> dp(i, vector<int>(j, 7));

        return solve(i - 1, j - 1, grid, dp);
    }
};