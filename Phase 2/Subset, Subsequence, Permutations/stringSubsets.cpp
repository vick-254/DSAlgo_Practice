#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> subset2(string p, string up)
{

    vector<string> ans;

    if (up.length() == 0)
    {
        ans.push_back(p);
        return ans;
    }

    char ch = up[0];

    vector<string> ans1 = subset2(p, up.substr(1));
    vector<string> ans2 = subset2(p + ch, up.substr(1));
    ans.insert(ans.end(), ans1.begin(), ans1.end());
    ans.insert(ans.end(), ans2.begin(), ans2.end());

    return ans;
}

void subset(string p, string up)
{

    if (up.length() == 0)
    {
        cout << p << endl;
        return;
    }

    char ch = up[0];

    subset(p, up.substr(1));
    subset(p + ch, up.substr(1));
}

int main()
{
    string str = "abc";
    string ans = "";
    vector<string> final = subset2(ans, str);
    for (string i : final)
    {
        cout << i << " ";
    }
}