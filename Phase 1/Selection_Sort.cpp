#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {

        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }
}

int main()
{

    int arr[6] = {11, 5, 3, 7, 4, 8};
    selectionSort(arr, 6);
}