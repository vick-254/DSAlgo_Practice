#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> maze(string p, int r, int c, vector<vector<bool>> obstacles)
{
    if (r == obstacles.size() - 1 && c == obstacles[0].size() - 1)
    {
        vector<string> ans;
        ans.push_back(p);
        return ans;
    }
    vector<string> ans;
    vector<string> down;
    vector<string> right;
    if (obstacles[r][c] == false)
    {
        vector<string> hello;
        return hello;
    }

    if (r < obstacles.size() - 1)
    {
        down = maze(p + 'D', r + 1, c, obstacles);
    }
    if (c < obstacles[0].size() - 1)
    {
        right = maze(p + 'R', r, c + 1, obstacles);
    }

    ans.insert(ans.end(), down.begin(), down.end());
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}

int main()
{

    vector<vector<bool>> obstacles = {{true, true, true}, {true, false, true}, {true, true, true}};
    vector<string> ans = maze("", 0, 0, obstacles);
    for (string i : ans)
    {
        cout << i << endl;
    }
}