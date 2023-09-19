#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dis(V, 1e8);
        dis[S] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];

                if (dis[u] != 1e8 && dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                }
            }
        }

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dis[u] != 1e8 && dis[u] + w < dis[v])
            {
                return {-1};
            }
        }
        return dis;
    }
};