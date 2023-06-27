#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> mazePath(string p, int r, int c)
{

    if (r == 1 && c == 1)
    {
        vector<string> ans;
        ans.push_back(p);
        return ans;
    }
    vector<string> ans;
    vector<string> down;
    vector<string> right;
    if (r > 1)
    {
        down = mazePath(p + 'D', r - 1, c);
    }
    if (c > 1)
    {
        right = mazePath(p + 'R', r, c - 1);
    }

    ans.insert(ans.end(), down.begin(), down.end());
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}

int main()
{

    vector<string> ans = mazePath("", 3, 3);
    for (string i : ans)
    {
        cout << i << endl;
    }
}