#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (auto it = mpp.begin(); it != mpp.end(); it++)
        {
            pq.push({(it->second), (it->first) * -1});
        }
        while (!pq.empty())
        {
            for (int i = 0; i < pq.top().first; i++)
            {
                ans.push_back(pq.top().second * -1);
            }

            pq.pop();
        }
        return ans;
    }
};