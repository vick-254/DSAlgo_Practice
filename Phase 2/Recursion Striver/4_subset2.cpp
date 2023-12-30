#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int size)
    {

        ans.push_back(ds);

        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);

            solve(i + 1, arr, ans, ds, size);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int size = nums.size();
        solve(0, nums, ans, ds, size);

        return ans;
    }
};