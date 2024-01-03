#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int maxAreaHistogram(vector<int> heights)
    {
        int n = heights.size();
        vector<int> nsl;
        vector<int> nsr;
        stack<pair<int, int>> st1;
        stack<pair<int, int>> st2;

        for (int i = 0; i < n; i++)
        {
            if (st1.empty())
                nsl.push_back(-1);

            else if (st1.size() > 0 && st1.top().first >= heights[i])
            {
                while (st1.size() > 0 && st1.top().first >= heights[i])
                    st1.pop();
                if (st1.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(st1.top().second);
            }
            else if (st1.size() > 0 && st1.top().first < heights[i])
                nsl.push_back(st1.top().second);
            st1.push({heights[i], i});
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (st2.empty())
                nsr.push_back(n);

            else if (st2.size() > 0 && st2.top().first >= heights[i])
            {
                while (st2.size() > 0 && st2.top().first >= heights[i])
                    st2.pop();
                if (st2.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(st2.top().second);
            }
            else if (st2.size() > 0 && st2.top().first < heights[i])
                nsr.push_back(st2.top().second);
            st2.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (nsr[i] - nsl[i] - 1) * heights[i]);
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v(n, 0);
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            v[i] = (matrix[0][i] == '1' ? 1 : 0);
        }
        ans = max(ans, maxAreaHistogram(v));

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    v[j] = 0;
                else
                {
                    v[j] += 1;
                }
            }
            ans = max(ans, maxAreaHistogram(v));
        }
        return ans;
    }
};