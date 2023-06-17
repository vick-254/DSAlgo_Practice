#include <iostream>
#include <vector>
using namespace std;

void binarySearch(vector<vector<int>> &matrix, int key)
{

    int s = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int e = (row * col) - 1;
    int mid = s + (e - s) / 2;
    int count = -1;
    while (s <= e)
    {
        int element = matrix[mid / col][mid % col];
        if (element == key)
        {
            cout << "Element found at: " << (mid / col) << " " << (mid % col) << endl;
            count = 1;
            break;
        }
        else if (element < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    if (count == -1)
    {
        cout << "Element not found" << endl;
    }
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    binarySearch(matrix, 8);
}