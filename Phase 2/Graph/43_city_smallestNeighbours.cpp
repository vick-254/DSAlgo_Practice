#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int threshold)
    {

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for (auto it : edges)
        {
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
        {
            dis[i][i] = 0;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int cntmax = n + 1;
        int city = -1;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] <= threshold)
                {

                    cnt++;
                }
            }
            if (cntmax >= cnt)
            {
                cntmax = cnt;
                city = i;
            }
        }
        return city;
    }
};