#include <iostream>
using namespace std;

int uniqueElement(int arr[], int size)
{

    int ans = 0;

    for (int i = 0; i < size; i++)
    {

        ans = ans ^ arr[i];
    }
    return ans;
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

    int ans = uniqueElement(arr, size);
    cout << "The unique element is " << ans << endl;
}