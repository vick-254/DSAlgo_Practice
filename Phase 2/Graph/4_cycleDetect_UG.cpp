#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool isCyclic(int src, vector<int> adj[], int vis[])
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if (prev != it)
                    return 1;
            }
        }
        return 0;
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
                if (isCyclic(i, adj, vis) == 1)
                    return true;
            }
        }
        return false;
    }
};