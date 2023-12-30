#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void solve(int ind, vector<int> &arr, vector<int> &ans, int size, int sum)
    {
        if (ind == size)
        {
            ans.push_back(sum);
            return;
        }

        sum = sum + arr[ind];
        solve(ind + 1, arr, ans, size, sum);
        sum = sum - arr[ind];
        solve(ind + 1, arr, ans, size, sum);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum = 0;
        solve(0, arr, ans, N, sum);
        return ans;
    }
};