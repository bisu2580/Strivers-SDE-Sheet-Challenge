#include <bits/stdc++.h>
using namespace std;
bool isSafe(int row, int col, vector<vector<int>> board, int n)
{
    int i = row, j = col;
    // row check
    while (j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        j--;
    }
    // upper left diagonal
    i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }
    // lower left diagonal
    i = row, j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }
    return true;
}
void addBoard(vector<vector<int>> &board, vector<vector<int>> &ans)
{
    vector<int> temp;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
void solve(vector<vector<int>> &board, int col, int n, vector<vector<int>> &ans)
{
    // Base Case
    if (col >= n)
    {
        addBoard(board, ans);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(board, col + 1, n, ans);
            // Backtrack
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col = 0;
    vector<vector<int>> ans;
    solve(board, col, n, ans);
    return ans;
}
int main()
{
    vector<vector<int>> ans = solveNQueens(4);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}