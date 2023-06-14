#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end == mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{

    int size;
    cin >> size;
    int arr[100];

    for (int i = 0; i < size; i++)
    {

        cin >> arr[i];
    }

    int sum = 0;
    cin >> sum;
    int ans = binarySearch(arr, size, sum);
    if (ans == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index : " << ans << endl;
    }
}
