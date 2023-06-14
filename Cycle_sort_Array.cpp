#include <iostream>
using namespace std;

void cycleSort(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        int correct = arr[i] - 1;
        if (arr[correct] != arr[i])
        {
            swap(arr[correct], arr[i]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[9] = {1, 6, 2, 5, 3, 4, 7, 9, 8};
    cycleSort(arr, 9);
}