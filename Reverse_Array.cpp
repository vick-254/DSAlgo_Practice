#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {

        swap(arr[start], arr[end]);
        start += 1;
        end -= 1;
    }

    cout << "reversed array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
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

    reverseArray(arr, size);
}
