#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds, int size)
    {
        if (ind == size)
        {
            if (target == 0)
            {
                ans.push_back(ds);
                return;
            }
            return;
        }

        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            solve(ind, arr, target - arr[ind], ans, ds, size);
            ds.pop_back();
        }
        solve(ind + 1, arr, target, ans, ds, size);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int size = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, candidates, target, ans, ds, size);
        return ans;
    }
};