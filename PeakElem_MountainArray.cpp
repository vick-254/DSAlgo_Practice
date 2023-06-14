#include <iostream>
using namespace std;

int peakElement(int arr[], int size)
{

    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while (start < end)
    {

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {

            break;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return mid;
}

int main()
{

    int arr[6] = {1, 2, 4, 6, 3, 2};
    int ans = peakElement(arr, 6);
    cout << ans << endl;
}
