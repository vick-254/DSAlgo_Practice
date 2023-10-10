#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

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
        if (n == parent[n])
            return n;

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
            size[ulp_v] += size[ulp_u];
        }

        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        int m = edge.size();
        int maxedges = 0;
        int cnt = 0;
        DisjointSet ds(n);
        for (int i = 0; i < m; i++)
        {
            if (ds.findUPar(edge[i][0]) == ds.findUPar(edge[i][1]))
            {
                maxedges++;
            }
            else
            {
                ds.unionBySize(edge[i][0], edge[i][1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ds.findUPar(i) == i)
                cnt++;
        }

        if (maxedges < cnt - 1)
            return -1;
        return cnt - 1;
    }
};