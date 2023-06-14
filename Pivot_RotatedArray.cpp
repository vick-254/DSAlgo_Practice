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
        else if (arr[mid] < arr[0])
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return mid;
}

int main()
{

    int arr[6] = {5, 6, 1, 2, 3, 4};
    int ans = pivotElement(arr, 6);
    cout << ans << endl;
}