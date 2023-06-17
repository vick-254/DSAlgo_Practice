#include <iostream>
using namespace std;

void rowWiseSum(int arr[][4], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        int ans = 0;
        for (int j = 0; j < col; j++)
        {
            ans = ans + arr[i][j];
        }
        cout << ans << " ";
    }
}

int main()
{

    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    rowWiseSum(arr, 3, 4);
}