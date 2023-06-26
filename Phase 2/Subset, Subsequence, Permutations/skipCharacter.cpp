#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string skip(string str, int index)
{

    string ans = "";

    if (index == str.length())
        return ans;

    if (str[index] == 'a')
    {

        return skip(str.substr(index + 1), index);
    }

    ans.push_back(str[index]);

    return ans + skip(str.substr(index + 1), index);
}

int main()
{

    string str = "baccad";
    string ans = skip(str, 0);
    cout << ans;
}