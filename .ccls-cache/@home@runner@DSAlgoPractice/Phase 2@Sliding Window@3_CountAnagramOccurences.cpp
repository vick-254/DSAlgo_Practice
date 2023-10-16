#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(string pat, string txt)
    {
        map<char, int> mpp;

        for (int i = 0; i < pat.length(); i++)
        {
            mpp[pat[i]]++;
        }
        int ans = 0;
        int i = 0, j = 0;
        int count = mpp.size();

        while (j < txt.length())
        {
            if (mpp.find(txt[j]) != mpp.end())
            {
                mpp[txt[j]]--;
                if (mpp[txt[j]] == 0)
                    count--;
            }

            if (j - i + 1 < pat.length())
                j++;

            else if (j - i + 1 == pat.length())
            {
                if (count == 0)
                    ans++;
                if (mpp.find(txt[i]) != mpp.end())
                {
                    mpp[txt[i]]++;
                    if (mpp[txt[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};