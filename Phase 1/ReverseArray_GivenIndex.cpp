#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{

    int s = m + 1;
    int e = arr.size() - 1;
    while (s <= e)
    {

        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    reverseArray(arr, 3);
    for (int i : arr)
    {
        cout << i << " ";
    }
}