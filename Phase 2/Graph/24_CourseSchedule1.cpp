#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int V, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<int> adj[V];
        for (auto it : prerequisites)
        {
            adj[it.first].push_back(it.second);
        }

        queue<int> q;
        vector<int> indegree(V, 0);
        vector<int> ans;

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

        if (ans.size() < V)
            return false;
        else
            return true;
    }
};