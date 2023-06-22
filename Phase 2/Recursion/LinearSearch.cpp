#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{

    if (size == 0)
    {
        return 0;
    }

    if (arr[0] != key)
        return linearSearch(arr + 1, size - 1, key);

    if (arr[0] == key)
        return 1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    bool a = linearSearch(arr, 5, 4);
    cout << a;
}