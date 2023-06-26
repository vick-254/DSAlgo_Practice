#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> pad(string p, string up)
{

    if (up.length() == 0)
    {
        vector<string> ans;
        ans.push_back(p);
        return ans;
    }

    vector<string> ans;

    char ch = up[0];
    int digit = ch - '0';

    for (int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        vector<string> belowCalls = pad(p + char('a' + i), up.substr(1));
        ans.insert(ans.end(), belowCalls.begin(), belowCalls.end());
    }

    return ans;
}

int main()
{
    string str = "12";
    vector<string> ans = pad("", str);
    for (string i : ans)
    {
        cout << i << " ";
    }
}