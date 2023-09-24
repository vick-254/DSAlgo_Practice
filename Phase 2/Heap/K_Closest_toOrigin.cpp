#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int r = points.size();

        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < r; i++)
        {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty())
        {
            vector<int> level;
            auto i = pq.top();
            pq.pop();
            level.push_back(i.second.first);
            level.push_back(i.second.second);
            ans.push_back(level);
        }
        return ans;
    }
};