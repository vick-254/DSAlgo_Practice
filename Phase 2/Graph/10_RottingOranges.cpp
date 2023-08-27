#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        int fresh = 0;
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({0, {i, j}});
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int time = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int t = q.front().first;
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({t + 1, {nrow, ncol}});
                    vis[nrow][ncol] = 2;
                    fresh--;
                }
            }
        }
        if (fresh != 0)
            return -1;

        return time;
    }
};