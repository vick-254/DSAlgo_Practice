#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int delcol[4] = {0, 1, 0, -1};
        int delrow[4] = {-1, 0, 1, 0};

        queue<pair<int, pair<int, int>>> q;
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        q.push({0, {source.first, source.second}});

        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), 1e9));
        dis[source.first][source.second] = 0;

        while (!q.empty())
        {
            auto node = q.front().second;
            int row = node.first;
            int col = node.second;
            int dis0 = q.front().first;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && ncol < grid[0].size() && ncol >= 0 && nrow < grid.size() && grid[nrow][ncol] == 1)
                {
                    if (dis[nrow][ncol] > dis0 + 1)
                    {
                        dis[nrow][ncol] = dis0 + 1;

                        if (destination.first == nrow && destination.second == ncol)
                        {
                            return dis[nrow][ncol];
                        }
                        q.push({dis[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        if (dis[destination.first][destination.second] == 1e9)
            return -1;
        return dis[destination.first][destination.second];
    }
};