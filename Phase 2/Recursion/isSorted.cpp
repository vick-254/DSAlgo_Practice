#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> arr)
{

    int size = arr.size();
    if (size == 0 || size == 1)
    {
        return 1;
    }

    if (arr[size - 1] > arr[size - 2])
    {
        arr.pop_back();
        return isSorted(arr);
    }

    return 0;
}

int main()
{

    vector<int> arr = {1, 2, 3, 5, 4};
    bool a = isSorted(arr);
    cout << a;
}
