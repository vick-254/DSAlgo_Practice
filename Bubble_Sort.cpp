#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }
}

int main()
{

    int arr[6] = {11, 5, 3, 7, 4, 8};
    bubbleSort(arr, 6);
}