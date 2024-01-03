#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> nearestSmallestLeft(vector<int> &heights, int n)
    {
        vector<int> nsl;
        stack<pair<int, int>> st1;

        for (int i = 0; i < n; i++)
        {
            if (st1.empty())
                nsl.push_back(-1);
            else if (st1.size() > 0 && st1.top().first >= heights[i])
            {
                while (st1.size() > 0 && st1.top().first >= heights[i])
                    st1.pop();
                if (st1.size() == 0)
                    nsl.push_back(-1);
                else
                    nsl.push_back(st1.top().second);
            }
            else if (st1.size() > 0 && st1.top().first < heights[i])
                nsl.push_back(st1.top().second);
            st1.push({heights[i], i});
        }
        return nsl;
    }

    vector<int> nearestSmallestRight(vector<int> &heights, int n)
    {
        vector<int> nsr;
        stack<pair<int, int>> st2;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st2.empty())
                nsr.push_back(n);
            else if (st2.size() > 0 && st2.top().first >= heights[i])
            {
                while (st2.size() > 0 && st2.top().first >= heights[i])
                    st2.pop();
                if (st2.size() == 0)
                    nsr.push_back(n);
                else
                    nsr.push_back(st2.top().second);
            }
            else if (st2.size() > 0 && st2.top().first < heights[i])
                nsr.push_back(st2.top().second);
            st2.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());
        return nsr;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nsl = nearestSmallestLeft(heights, n);
        vector<int> nsr = nearestSmallestRight(heights, n);

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (nsr[i] - nsl[i] - 1) * heights[i]);
        }

        return ans;
    }
};