#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    bool swapped;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }
}

int main()
{

    int arr[6] = {1, 2, 8, 4, 5, 6};
    bubbleSort(arr, 6);
}