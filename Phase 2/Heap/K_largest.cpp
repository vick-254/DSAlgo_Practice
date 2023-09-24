#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            q.push(arr[i]);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};