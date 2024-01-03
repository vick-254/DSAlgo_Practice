#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int len = 0;
        int ans = 0;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                {
                    len = i - st.top();
                    ans = max(ans, len);
                }
            }
            else if (s[i] == '(')
            {
                st.push(i);
            }
        }
        return ans;
    }
};