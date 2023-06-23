#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    int i = 0;
    int j = 0;
    k = s;

    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }

    while (i < len1)
    {
        arr[k++] = first[i++];
    }

    while (j < len2)
    {
        arr[k++] = second[j++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(vector<int> &arr, int s, int e)
{

    int mid = s + (e - s) / 2;
    if (s >= e)
        return;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    vector<int> arr = {1, 2, 56, 3, 2, 6, 56, 234, 5, 324, 6};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
}