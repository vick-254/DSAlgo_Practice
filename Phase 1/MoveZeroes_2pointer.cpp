#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &arr)
{

    int i = 0;

    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    for (int j = 0; j < arr.size(); j++)
    {
        cout << arr[j] << " ";
    }
}

int main()
{

    vector<int> nums = {11, 0, 2, 4, 0, 0, 6, 7, 0, 9};
    moveZeroes(nums);
}