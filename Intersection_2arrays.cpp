#include <iostream>
using namespace std;

int intersectionArrays(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0;
    int j = 0;
    int a = -1;
    while (i < size1 && j < size2)
    {

        if (arr1[i] < arr1[j])
        {

            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {

            cout << arr2[j] << " ";
            i++;
            j++;
            a = 1;
        }
    }
    return a;
}

int main()
{
    int arr1[6] = {1, 3, 4, 4, 5, 6};
    int arr2[4] = {1, 2, 4, 5};
    int ans = intersectionArrays(arr1, 6, arr2, 4);
    if (ans == -1)
    {
        cout << "-1";
    }
}