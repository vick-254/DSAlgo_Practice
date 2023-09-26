#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0;
        int n = s.length();
        int ans = 0;
        map<char, int> mpp;
        while (j < n)
        {
            mpp[s[j]]++;
            if (mpp.size() < j - i + 1)
            {
                while (mpp.size() < j - i + 1)
                {
                    mpp[s[i]]--;
                    if (mpp[s[i]] == 0)
                    {
                        mpp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }

            else if (mpp.size() == j - i + 1)
            {
                ans = max(ans, j - i + 1);

                j++;
            }
        }
        return ans;
    }
};