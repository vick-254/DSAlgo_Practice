#include <iostream>

using namespace std;

void duplicateElements(int arr[], int size)
{

    int i = 0;
    while (i < size)
    {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }

    int dupArr[100];
    int x = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            dupArr[x] = arr[i];

            x++;
        }
    }

    for (int j = 0; j < x; j++)
    {
        cout << dupArr[j] << " ";
    }
}

int main()
{

    int size;
    cin >> size;
    int arr[100];

    for (int i = 0; i < size; i++)
    {

        cin >> arr[i];
    }

    duplicateElements(arr, size);
}
