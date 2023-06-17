#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<vector<int>> &matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();
    int startingRow = 0;
    int startingCol = col - 1;

    while (startingRow < row && startingCol >= 0)
    {

        int element = matrix[startingRow][startingCol];
        if (element == target)
        {
            return true;
        }
        else if (element > target)
        {
            startingCol--;
        }
        else if (element < target)
        {
            startingRow++;
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 22}, {18, 21, 23, 26, 30}};
    bool ans = binarySearch(matrix, 27);

    cout << ans;
}
