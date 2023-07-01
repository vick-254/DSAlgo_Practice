#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr, int r, int c)
{
    if (r == 0)
    {

        return;
    }

    if (c < r)
    {
        if (arr[c] > arr[c + 1])
        {
            swap(arr[c], arr[c + 1]);
        }
        bubbleSort(arr, r, c + 1);
    }
    else
    {
        bubbleSort(arr, r - 1, 0);
    }
}

int main()
{
    vector<int> arr = {99, 7, 8, 33, 6, 5};
    bubbleSort(arr, 6, 6);
    for (int i : arr)
    {
        cout << i << " ";
    }
}