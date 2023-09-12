#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<pair<int, int>> &temp, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});

        int row0 = q.front().first;
        int col0 = q.front().second;
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {0, 1, 0, -1};
            int delcol[] = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    temp.push_back({nrow - row0, ncol - col0});
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        set<vector<pair<int, int>>> st;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;
                    bfs(i, j, vis, temp, grid);
                    st.insert(temp);
                }
            }
        }

        return st.size();
    }
};