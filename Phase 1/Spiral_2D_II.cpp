#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{

    int count = 0;
    int total = n * n;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n - 1;
    int endingCol = n - 1;
    vector<vector<int>> matrix(n, vector<int>(n));
    int value = 1;

    while (count < total)
    {

        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            matrix[startingRow][index] = value;
            count++;
            value++;
        }
        startingRow++;

        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            matrix[index][endingCol] = value;
            count++;
            value++;
        }
        endingCol--;
        for (int index = endingCol; count < total && index >= startingCol; index--)
        {
            matrix[endingRow][index] = value;
            count++;
            value++;
        }
        endingRow--;
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            matrix[index][startingCol] = value;
            count++;
            value++;
        }
        startingCol++;
    }
    return matrix;
}

int main()
{

    vector<vector<int>> ans = generateMatrix(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
    }
}
