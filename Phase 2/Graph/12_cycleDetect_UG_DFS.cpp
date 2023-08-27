#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool cycle(int node, int parent, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (cycle(it, node, adj, vis) == true)
                    return true;
            }
            else if (parent != it)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (cycle(i, -1, adj, vis) == true)
                    return true;
            }
        }
        return false;
    }
};