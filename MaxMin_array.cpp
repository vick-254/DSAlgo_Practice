#include <iostream>
#include <climits>
using namespace std;

int maxArray(int arr[], int size)
{

    int min = INT_MIN;

    for (int i = 0; i < size; i++)
    {

        if (i[arr] > min)
        {

            min = i[arr];
        }
    }
    return min;
}

int minArray(int arr[], int size)
{

    int max = INT_MAX;
    for (int i = 0; i < size; i++)
    {

        if (i[arr] < max)
        {

            max = i[arr];
        }
    }
    return max;
}

int main()
{

    int arr[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    int max = maxArray(arr, 6);
    int min = minArray(arr, 6);

    cout << "Max of array: " << max << endl;
    cout << "Min of array: " << min << endl;
}