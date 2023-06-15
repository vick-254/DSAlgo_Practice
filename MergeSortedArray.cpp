#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
{

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(), arr1.end());

    for (int j = 0; j < n + m; j++)
    {
        cout << arr1[j] << " ";
    }
}

int main()
{

    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8};
    merge(arr1, 5, arr2, 4);

    return 0;
}