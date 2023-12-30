#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<int> &nums, vector<bool> &flag, vector<vector<int>> &ans, vector<int> &ds, int size)
    {
        if (ds.size() == nums.size())
            ans.push_back(ds);
        for (int i = 0; i < nums.size(); i++)
        {
            if (flag[i] == true)
                continue;
            flag[i] = true;
            ds.push_back(nums[i]);
            solve(nums, flag, ans, ds, size);
            flag[i] = false;
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> flag(6, false);
        solve(nums, flag, ans, ds, size);
        return ans;
    }
};