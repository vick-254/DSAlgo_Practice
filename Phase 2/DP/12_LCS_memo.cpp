#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (text1[ind1] == text2[ind2])
            return 1 + solve(ind1 - 1, ind2 - 1, text1, text2, dp);

        return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, text1, text2, dp), solve(ind1, ind2 - 1, text1, text2, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int ind1 = text1.length();
        int ind2 = text2.length();

        vector<vector<int>> dp(ind1, vector<int>(ind2, -1));
        return solve(ind1 - 1, ind2 - 1, text1, text2, dp);
    }
};