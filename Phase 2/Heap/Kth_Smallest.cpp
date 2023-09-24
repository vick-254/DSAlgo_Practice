#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;

        for (int i = 0; i <= r - l; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};