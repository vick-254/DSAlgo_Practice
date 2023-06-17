#include <iostream>
using namespace std;

int pairSum(int arr[], int size, int sum)
{

    int i = 0;
    int j = 0;
    int a = -1;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << arr[i] << " " << arr[j] << endl;
                a = 1;
            }
        }
    }
    return a;
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

    int sum = 0;
    cin >> sum;

    int ans = pairSum(arr, size, sum);
    if (ans == -1)
    {
        cout << -1 << endl;
    }
}
