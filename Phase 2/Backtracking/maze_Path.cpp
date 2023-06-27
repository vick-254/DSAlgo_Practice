#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mazeAll(string p, int r, int c, vector<vector<int>> maze, int count)
{
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        maze[r][c] = count;
        for (int i = 0; i < maze.size(); i++)
        {
            for (int j = 0; j < maze[0].size(); j++)
            {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << p << endl;
        cout << endl;
        return;
    }

    if (maze[r][c] != 0)
    {
        return;
    }

    maze[r][c] = count;

    if (r < maze.size() - 1)
    {
        mazeAll(p + 'D', r + 1, c, maze, count + 1);
    }
    if (r > 0)
    {
        mazeAll(p + 'U', r - 1, c, maze, count + 1);
    }
    if (c < maze[0].size() - 1)
    {
        mazeAll(p + 'R', r, c + 1, maze, count + 1);
    }
    if (c > 0)
    {
        mazeAll(p + 'L', r, c - 1, maze, count + 1);
    }

    maze[r][c] = 0;
}

int main()
{

    vector<vector<int>> maze = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    mazeAll("", 0, 0, maze, 1);
}