#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target, int s, int e)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[s] <= arr[mid])
    {
        if (arr[mid] > target && arr[s] <= target)
        {
            return binarySearch(arr, target, s, mid - 1);
        }
        else
        {
            return binarySearch(arr, target, mid + 1, e);
        }
    }

    if (target > arr[mid] && target <= arr[e])
    {
        return binarySearch(arr, target, mid + 1, e);
    }
    else
    {
        return binarySearch(arr, target, s, mid - 1);
    }
}

int main()
{

    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int a = binarySearch(arr, 5, 0, 8);
    cout << a;
}