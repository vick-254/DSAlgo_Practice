#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{

    int s = 0;
    int e = 1;

    while (e < size)
    {
        swap(arr[s], arr[e]);
        s += 2;
        e += 2;
    }

    cout << "Alternate Swappeds Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
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

    swapAlternate(arr, size);
}
