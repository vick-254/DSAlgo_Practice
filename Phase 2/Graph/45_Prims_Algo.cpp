#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            if (!vis[it.second])
            {
                vis[it.second] = 1;
                sum = sum + it.first;
                for (auto i : adj[it.second])
                {
                    if (!vis[i[0]])
                    {

                        pq.push({i[1], i[0]});
                    }
                }
            }
        }
        return sum;
    }
};