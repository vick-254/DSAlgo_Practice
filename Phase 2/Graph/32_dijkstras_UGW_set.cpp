#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dis(V, 1e9);

        dis[S] = 0;

        st.insert({0, S});

        while (!st.empty())
        {
            auto i = *(st.begin());
            int node = i.second;
            int dis0 = i.first;
            st.erase(i);

            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if (dis[adjNode] > dis0 + edgeWeight)
                {
                    if (dis[adjNode] != 1e9)
                        st.erase({dis[adjNode], adjNode});

                    dis[adjNode] = dis0 + edgeWeight;
                    st.insert({dis0 + edgeWeight, adjNode});
                }
            }
        }
        return dis;
    }
};