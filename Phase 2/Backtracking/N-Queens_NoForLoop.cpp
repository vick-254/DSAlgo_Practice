#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> board, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    int maxLeft = min(row, col);

    for (int i = 0; i <= maxLeft; i++)
    {
        if (board[row - i][col - i] == 'Q')
            return false;
    }

    int s = board.size() - col - 1;

    int maxRight = min(row, s);

    for (int i = 0; i <= maxRight; i++)
    {
        if (board[row - i][col + i] == 'Q')
            return false;
    }

    return true;
}

void helper(vector<vector<string>> &ans, vector<string> board, int row, int col)
{

    if (row == board.size())
    {
        ans.push_back(board);

        return;
    }

    if (col >= board[0].length())
    {

        return;
    }

    if (isSafe(board, row, col) == true)
    {

        board[row][col] = 'Q';

        helper(ans, board, row + 1, 0);

        board[row][col] = '.';
    }

    helper(ans, board, row, col + 1);
}

vector<vector<string>> solveNQueens(int n)
{

    string str(n, '.');
    vector<string> board(n, str);

    vector<vector<string>> ans;
    helper(ans, board, 0, 0);
    return ans;
}

int main()
{

    vector<vector<string>> ans = solveNQueens(5);
    for (vector<string> i : ans)
    {
        for (string j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}