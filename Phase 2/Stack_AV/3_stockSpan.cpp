#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int arr[], int n)
    {
        vector<int> ans;
        vector<int> ans2(n, 1);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {

            if (st.empty())
                ans.push_back(-1);

            else if (st.size() > 0 && st.top().first <= arr[i])
            {
                while (st.size() > 0 && st.top().first <= arr[i])
                {
                    st.pop();
                }

                if (st.size() == 0)
                    ans.push_back(-1);
                else
                    ans.push_back(st.top().second);
            }

            else if (st.size() > 0 && st.top().first > arr[i])
                ans.push_back(st.top().second);

            st.push({arr[i], i});
        }

        for (int i = 0; i < n; i++)
        {
            ans2[i] = i - ans[i];
        }
        return ans2;
    }
};