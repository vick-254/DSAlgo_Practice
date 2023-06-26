#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> dice(string p, int target)
{

    if (target == 0)
    {
        vector<string> ans;
        ans.push_back(p);
        return ans;
    }

    vector<string> ans;

    for (int i = 1; i <= target; i++)
    {
        vector<string> belowCalls = dice(p + to_string(i), target - i);
        ans.insert(ans.end(), belowCalls.begin(), belowCalls.end());
    }
    return ans;
}

int main()
{
    vector<string> ans = dice("", 4);
    for (string i : ans)
    {
        cout << i << endl;
    }
}