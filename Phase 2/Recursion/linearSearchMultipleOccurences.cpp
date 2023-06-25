#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> linearSearch(vector<int> &arr, int target, int s, int e)
{

    vector<int> list;

    if (s > e)
        return list;

    if (arr[s] == target)
    {
        list.push_back(s);
    }
    vector<int> ans = linearSearch(arr, target, s + 1, e);

    list.insert(list.end(), ans.begin(), ans.end());

    return list;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 4};
    vector<int> ans = linearSearch(arr, 4, 0, 7);
    for (int i : ans)
    {
        cout << i << " ";
    }
}