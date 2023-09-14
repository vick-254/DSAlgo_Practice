#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, st, vis, adj);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> ans;
        stack<int> st;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }
        int k = st.size();
        for (int i = 0; i < k; i++)
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};