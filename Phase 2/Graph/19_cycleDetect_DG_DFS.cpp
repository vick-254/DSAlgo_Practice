#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int node, vector<int> &vis, vector<int> &pathvis, vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (check(it, vis, pathvis, adj) == true)
                    return true;
            }
            else if (vis[it] == pathvis[it] == 1)
                return true;
        }
        pathvis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (check(i, vis, pathvis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};