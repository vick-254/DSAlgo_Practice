#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> permutations(string p, string up)
{
    if (up.length() == 0)
    {
        vector<string> ans;
        ans.push_back(p);

        return ans;
    }

    vector<string> ans;

    char ch = up[0];
    for (int i = 0; i < p.length() + 1; i++)
    {
        string first = p.substr(0, i);
        string last = p.substr(i);

        vector<string> belowCalls = permutations(first + ch + last, up.substr(1));
        ans.insert(ans.end(), belowCalls.begin(), belowCalls.end());
    }

    return ans;
}

int main()
{
    string str = "abc";
    vector<string> ans = permutations("", str);
    for (string i : ans)
    {
        cout << i << " ";
    }
}