#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool bip(int start, vector<int> adj[], vector<int> &vis)
    {
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (vis[it] == -1)
                {
                    vis[it] = !vis[node];
                    q.push(it);
                }
                else if (vis[it] == vis[node])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> vis(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == -1)
            {
                if (bip(i, adj, vis) == 0)
                    return 0;
            }
        }
        return 1;
    }
};