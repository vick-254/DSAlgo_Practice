#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];

        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        set<pair<int, int>> st;
        st.insert({0, 1});

        vector<int> dis(n + 1, 1e9);

        dis[1] = 0;

        vector<int> parent(n + 1);

        vector<int> ans;
        ans.push_back(1);

        stack<int> sta;

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        while (!st.empty())
        {
            auto i = *(st.begin());
            int node = i.second;
            int dis0 = i.first;
            st.erase(i);

            for (auto it : adj[node])
            {
                int edgeWeight = it.second;
                int adjNode = it.first;

                if (dis[adjNode] > dis0 + edgeWeight)
                {
                    if (dis[adjNode] != 1e9)
                        st.erase({dis[adjNode], adjNode});

                    dis[adjNode] = dis0 + edgeWeight;

                    st.insert({dis[adjNode], adjNode});

                    parent[adjNode] = node;
                }
            }
        }

        int nd = n;

        while (nd != parent[nd])
        {
            sta.push(nd);
            nd = parent[nd];
        }

        while (!sta.empty())
        {
            ans.push_back(sta.top());
            sta.pop();
        }

        if (dis[n] == 1e9)
            return {-1};
        return ans;
    }
};