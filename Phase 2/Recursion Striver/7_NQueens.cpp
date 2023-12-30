#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(vector<string> &board, int row, int col)
    {
        int duprow = row;
        int dupcol = col;

        while (row > 0 && col > 0)
        {
            if (board[row - 1][col - 1] == 'Q')
                return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        while (row < board.size() - 1 && col > 0)
        {
            if (board[row + 1][col - 1] == 'Q')
                return false;
            row++;
            col--;
        }

        col = dupcol;
        row = duprow;

        while (col > 0)
        {
            if (board[row][col - 1] == 'Q')
                return false;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, ans, n);

        return ans;
    }
};