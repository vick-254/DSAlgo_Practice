#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>> &matrix)
{

    int n = matrix.size();

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseArray(vector<int> &arr, int size)
{

    int s = 0;
    int e = size - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void rotate(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    transpose(matrix);
    for (int i = 0; i < n; i++)
    {
        reverseArray(matrix[i], n);
    }
}

int main()
{

    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}