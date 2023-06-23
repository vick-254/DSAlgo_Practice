#include <iostream>
using namespace std;

void merge(int arr1[], int m, int arr2[], int n, int arr3[], int s)
{

        int i = 0, j = 0, count = 0;
    while (i < m && j < n && count < s)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[count] = arr1[i];
            i++;
            count++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[count] = arr2[j];
            j++;
            count++;
        }
        else if (arr1[i] == arr2[j])
        {
            arr3[count] = arr1[i];
            arr3[count + 1] = arr2[j];
            count++;
            i++;
            j++;
        }
    }
    while (i < m)
    {
        arr3[count] = arr1[i];
        count++;
        i++;
    }
    while (j < n)
    {
        arr3[count] = arr2[j];
        count++;
        j++;
    }
}

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};
    int arr3[8] = {0};
    merge(arr1, 5, arr2, 3, arr3, 8);

    for (int i : arr3)
    {
        cout << i << " ";
    }
}