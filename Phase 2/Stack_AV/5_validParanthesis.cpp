#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> st;
        map<char, char> mpp;

        mpp[']'] = '[';
        mpp['}'] = '{';
        mpp[')'] = '(';

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                st.push(s[i]);
                continue;
            }
            else if (st.empty())
                return false;
            else
            {
                if (st.top() == mpp[s[i]])
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
        }
        return st.empty() ? true : false;
    }
};