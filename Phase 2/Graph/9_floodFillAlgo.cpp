#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int delRow[], int delCol[], int inColor)
    {
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == inColor && ans[nrow][ncol] != color)
            {
                dfs(nrow, ncol, ans, image, color, delRow, delCol, inColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int inColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delCol[] = {0, 1, 0, -1};
        int delRow[] = {-1, 0, 1, 0};
        dfs(sr, sc, ans, image, color, delRow, delCol, inColor);
        return ans;
    }
};