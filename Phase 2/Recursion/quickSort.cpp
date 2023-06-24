#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{

    int pivot = s;
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= arr[pivot])
            count++;
    }

    int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        if (arr[i] <= arr[pivotIndex] && arr[j] >= arr[pivotIndex])
        {
            i++;
            j--;
        }

        if (arr[i] > arr[pivotIndex] && arr[j] >= arr[pivotIndex])
        {
            j--;
        }
        if (arr[i] <= arr[pivotIndex] && arr[j] < arr[pivotIndex])
        {
            i++;
        }
        if (arr[i] > arr[pivotIndex] && arr[j] < arr[pivotIndex])
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int s, int e)
{

    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{

    vector<int> arr = {1, 2, 5, 7, 3, 6, 34, 4, 56, 8, 67, 9};
    quickSort(arr, 0, 11);
    for (int i : arr)
    {
        cout << i << " ";
    }
}