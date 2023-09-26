#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        int ans = INT_MIN;
        int sum = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            sum = sum + arr[j];
            if (sum > k)
            {
                while (sum > k)
                {
                    sum = sum - arr[i];
                    i++;
                }
            }
            if (sum < k)
                j++;
            else if (sum == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
};