#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int start, int color, vector<int> adj[], vector<int> &vis)
    {
        vis[start] = color;
        for (auto it : adj[start])
        {
            if (vis[it] == -1)
            {
                if (check(it, !color, adj, vis) == 0)
                    return 0;
            }
            else if (vis[it] == vis[start])
                return 0;
        }
        return 1;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> vis(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == -1)
            {
                if (check(i, 0, adj, vis) == 0)
                    return 0;
            }
        }
        return 1;
    }
};