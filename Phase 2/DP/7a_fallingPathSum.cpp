#include <bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (c >= matrix[0].size() || c < 0)
        return -1e8;

    if (r == 0)
        return matrix[0][c];

    if (dp[r][c] != -1)
        return dp[r][c];

    int dleft = matrix[r][c] + solve(r - 1, c - 1, matrix, dp);
    int dright = matrix[r][c] + solve(r - 1, c + 1, matrix, dp);
    int up = matrix[r][c] + solve(r - 1, c, matrix, dp);

    return dp[r][c] = max(up, max(dleft, dright));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    int maxi = -1e8;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        maxi = max(maxi, solve(matrix.size() - 1, i, matrix, dp));
    }
    return maxi;
}