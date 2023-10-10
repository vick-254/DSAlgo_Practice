#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }
        return parent[n] = findUPar(parent[n]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_v] + size[ulp_u];
        }
        else if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_v] + size[ulp_u];
        }
        else if (size[ulp_u] == size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_v] + size[ulp_u];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                edges.push_back({it[1], {i, it[0]}});
            }
        }
        DisjointSet ds(V);

        sort(edges.begin(), edges.end());
        int mst = 0;

        for (auto it : edges)
        {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mst += w;
                ds.unionBySize(u, v);
            }
        }
        return mst;
    }
};