#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans;

        stack<long long> st;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(-1);

            else if (st.size() > 0 && st.top() <= arr[i])
            {
                while (!st.empty() && st.top() <= arr[i])
                    st.pop();
                if (st.size() == 0)
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());
            }

            else if (st.size() > 0 && st.top() > arr[i])
                ans.push_back(st.top());

            st.push(arr[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};