#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int ans = INT_MIN;

        map<char, int> mpp;

        int i = 0, j = 0;
        int t = s.length();
        while (j < t)
        {
            mpp[s[j]]++;
            if (mpp.size() < k)
            {
                j++;
            }
            else if (mpp.size() == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (mpp.size() > k)
            {
                while (mpp.size() > k)
                {
                    mpp[s[i]]--;
                    if (mpp[s[i]] == 0)
                        mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};