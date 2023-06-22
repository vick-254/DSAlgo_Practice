#include <iostream>
#include <vector>
using namespace std;

int getSum(int arr[], int size)
{

    if (size == 0)
        return 0;

    return arr[0] + getSum(arr + 1, size - 1);
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int ans = getSum(arr, 5);
    cout << ans;
}