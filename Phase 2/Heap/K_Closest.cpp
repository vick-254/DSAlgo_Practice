#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int size = arr.size();
    vector<int> ans;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    vector<int> ans = {6, 5, 9, 7, 8};
    vector<int> sol = findClosestElements(ans, 3, 7);
    for (auto i : sol)
    {
        cout << i << " - ";
    }
}