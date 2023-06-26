#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> subset(string p, string up)
{

    vector<string> ans;

    if (up.length() == 0)
    {
        ans.push_back(p);
        return ans;
    }

    char ch = up[0];

    vector<string> left = subset(p, up.substr(1));
    vector<string> right = subset(p + ch, up.substr(1));
    vector<string> ascii = subset(p + to_string(ch + 0), up.substr(1));
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    ans.insert(ans.end(), ascii.begin(), ascii.end());

    return ans;
}

int main()
{

    string str = "ab";
    string final = "";
    vector<string> ans = subset(final, str);
    for (string i : ans)
    {
        cout << i << " ";
    }
}