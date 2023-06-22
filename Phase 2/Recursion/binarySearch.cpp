#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int key, int s, int e)
{

    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (s > e)
    {
        return 0;
    }
    if (arr[mid] > key)
        return binarySearch(arr, key, s, mid - 1);

    if (arr[mid] < key)
        return binarySearch(arr, key, mid + 1, e);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = binarySearch(arr, 7, 0, 8);

    cout << ans;
}