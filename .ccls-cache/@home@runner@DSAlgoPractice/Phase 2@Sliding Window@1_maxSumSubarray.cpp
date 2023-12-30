#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int k, vector<int> &arr, int N)
    {
        long ans = INT_MIN;

        long sum = 0;

        int i = 0;
        int j = 0;

        while (j < N)
        {
            sum = sum + arr[j];
            if (j - i + 1 < k)
                j++;

            else if (j - i + 1 == k)
            {
                ans = max(ans, sum);
                sum = sum - arr[i];
                j++;
                i++;
            }
        }
        return ans;
    }
};