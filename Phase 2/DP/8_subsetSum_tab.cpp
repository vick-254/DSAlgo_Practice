#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, 0));

        for (int i = 0; i < arr.size(); i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        for (int ind = 1; ind < arr.size(); ind++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool nottake = dp[ind - 1][j];
                bool take = false;
                if (arr[ind] <= j)
                    take = dp[ind - 1][j - arr[ind]];

                dp[ind][j] = take || nottake;
            }
        }
        return dp[arr.size() - 1][sum];
    }
};