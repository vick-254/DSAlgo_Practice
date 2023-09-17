#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                topoSort(it.first, adj, st, vis);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        stack<int> st;
        vector<int> vis(N, 0);

        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        topoSort(0, adj, st, vis);

        vector<int> dis(N, 1e9);
        dis[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                dis[it.first] = min(dis[it.first], dis[node] + it.second);
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