#include <iostream>
using namespace std;

int firstPos(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
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
    return ans;
}

int lastPos(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
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
    return ans;
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

    int key = 0;
    cin >> key;

    int a = firstPos(arr, size, key);
    int b = lastPos(arr, size, key);

    cout << a << " " << b << endl;
}
