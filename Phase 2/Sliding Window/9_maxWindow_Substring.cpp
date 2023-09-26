#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> mpp;

        int i = 0, j = 0;
        for (int k = 0; k < t.length(); k++)
        {
            mpp[t[k]]++;
        }
        int minlen = INT_MAX;
        int start = 0;
        int count = mpp.size();

        while (j < s.length())
        {
            if (mpp.find(s[j]) != mpp.end())
            {
                mpp[s[j]]--;
                if (mpp[s[j]] == 0)
                    count--;
            }

            if (count > 0)
                j++;

            else if (count == 0)
            {

                while (count == 0)
                {

                    if (mpp.find(s[i]) != mpp.end())
                    {
                        mpp[s[i]]++;
                        if (mpp[s[i]] == 1)
                        {
                            count++;
                            if (minlen > j - i + 1)
                            {
                                minlen = j - i + 1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
                j++;
            }
        }

        if (minlen == INT_MAX)
            return "";
        return s.substr(start, minlen);
    }
};