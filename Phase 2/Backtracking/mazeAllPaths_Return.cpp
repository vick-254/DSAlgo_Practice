#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> mazeAll(string p, int r, int c, vector<vector<bool>> maze)
{
    vector<string> ans;
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {

        ans.push_back(p);

        return ans;
    }

    if (!maze[r][c])
    {
        vector<string> hello;
        return hello;
    }

    maze[r][c] = false;

    vector<string> left;
    vector<string> right;
    vector<string> up;
    vector<string> down;

    if (r < maze.size() - 1)
    {
        down = mazeAll(p + 'D', r + 1, c, maze);
    }
    if (r > 0)
    {
        up = mazeAll(p + 'U', r - 1, c, maze);
    }
    if (c < maze[0].size() - 1)
    {
        right = mazeAll(p + 'R', r, c + 1, maze);
    }
    if (c > 0)
    {
        left = mazeAll(p + 'L', r, c - 1, maze);
    }

    maze[r][c] = true;
    ans.insert(ans.end(), down.begin(), down.end());
    ans.insert(ans.end(), up.begin(), up.end());
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}

int main()
{

    vector<vector<bool>> maze = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<string> ans = mazeAll("", 0, 0, maze);
    for (string i : ans)
    {
        cout << i << endl;
    }
}