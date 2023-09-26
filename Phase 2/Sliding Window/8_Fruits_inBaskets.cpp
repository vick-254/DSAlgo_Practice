#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int ans = 0;
        int i = 0, j = 0;

        map<int, int> mpp;

        while (j < fruits.size())
        {
            mpp[fruits[j]]++;

            if (mpp.size() < 1)
                j++;

            else if (mpp.size() == 1)
            {
                ans = max(ans, j - i + 1);
                j++;
            }

            else if (mpp.size() == 2)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (mpp.size() > 2)
            {
                while (mpp.size() > 2)
                {

                    mpp[fruits[i]]--;
                    if (mpp[fruits[i]] == 0)
                        mpp.erase(fruits[i]);

                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};