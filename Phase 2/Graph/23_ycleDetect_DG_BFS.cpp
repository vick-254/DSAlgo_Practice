#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> ans;

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {

                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> ans = topoSort(V, adj);

        if (ans.size() < V)
            return true;
        else
            return false;
    }
};