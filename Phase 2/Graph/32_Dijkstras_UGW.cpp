#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9);
        dis[S] = 0;

        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis0 = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                if (dis[it[0]] > dis0 + it[1])
                {
                    pq.push({it[1] + dis0, it[0]});
                    dis[it[0]] = dis0 + it[1];
                }
            }
        }
        return dis;
    }
};