#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mazeAll(string p, int r, int c, vector<vector<bool>> maze)
{
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        cout << p << endl;
        return;
    }

    if (!maze[r][c])
    {
        return;
    }

    maze[r][c] = false;

    if (r < maze.size() - 1)
    {
        mazeAll(p + 'D', r + 1, c, maze);
    }
    if (r > 0)
    {
        mazeAll(p + 'U', r - 1, c, maze);
    }
    if (c < maze[0].size() - 1)
    {
        mazeAll(p + 'R', r, c + 1, maze);
    }
    if (c > 0)
    {
        mazeAll(p + 'L', r, c - 1, maze);
    }

    maze[r][c] = true;
}

int main()
{

    vector<vector<bool>> maze = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    mazeAll("", 0, 0, maze);
}