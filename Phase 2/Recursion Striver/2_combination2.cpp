#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int ind, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &ds, int size)
    {

        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], ans, ds, size);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int size = candidates.size();
        solve(0, candidates, target, ans, ds, size);
        return ans;
    }
};