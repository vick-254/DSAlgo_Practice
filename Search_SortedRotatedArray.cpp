#include <iostream>
using namespace std;

int pivotElement(int arr[], int size)
{

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
        {

            break;
        }
        else if (arr[mid] > arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return mid;
}

int searchSRArray(int arr[], int size, int key)
{

    int s = 0;
    int e = size - 1;

    int pivot = pivotElement(arr, size);

    if (key >= arr[0])
    {
        e = pivot - 1;
    }
    else
    {
        s = pivot;
    }
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            return mid;
        }
        mid = (s + e) / 2;
    }
    return mid;
}

int main()
{

    int arr[6] = {5, 6, 1, 2, 3, 4};
    int ans = searchSRArray(arr, 6, 6);
    cout << ans << endl;
}