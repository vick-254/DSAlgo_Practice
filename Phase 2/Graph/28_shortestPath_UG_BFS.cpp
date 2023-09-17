#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        queue<int> q;

        q.push(src);

        vector<int> adj[N];

        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dis(N, 1e9);
        dis[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {

                if (dis[it] > dis[node] + 1)
                {
                    dis[it] = dis[node] + 1;
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dis[i] == 1e9)
                dis[i] = -1;
        }

        return dis;
    }
};