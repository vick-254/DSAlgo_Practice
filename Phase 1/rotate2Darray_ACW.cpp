#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> ans;

    int startingCol = 0;
    int endingCol = n - 1;

    for (int i = endingCol; i >= startingCol; i--)
    {
        vector<int> tempAns;
        for (int j = 0; j < n; j++)
        {
            tempAns.push_back(matrix[j][i]);
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main()
{

    vector<vector<int>> matrix = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    vector<vector<int>> ans;
    ans = rotate(matrix);

    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}