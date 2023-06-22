#include <bits/stdc++.h>
using namespace std;
bool isSafe(int val, int matrix[9][9], int i, int j)
{
    // row
    for (int col = 0; col < 9; col++)
    {
        if (matrix[i][col] == val)
            return false;
    }
    // col
    for (int row = 0; row < 9; row++)
    {
        if (matrix[row][j] == val)
            return false;
    }
    // board
    for (int k = 0; k < 9; k++)
    {
        if (matrix[3 * (i / 3) + (k / 3)][(3 * (j / 3)) + (k % 3)] == val)
            return false;
    }
    return true;
}
bool isItSudoku(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(val, matrix, i, j))
                    {
                        matrix[i][j] = val;
                        bool nextSol = isItSudoku(matrix);
                        if (nextSol)
                        {
                            return true;
                        }
                        else
                        {
                            matrix[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int matrix[9][9] = {
        {9, 0, 0, 0, 2, 0, 7, 5, 0},
        {6, 0, 0, 0, 5, 0, 0, 4, 0},
        {0, 2, 0, 4, 0, 0, 0, 1, 0},
        {2, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 7, 0, 5, 0, 9, 0, 6, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 1},
        {0, 1, 0, 0, 0, 5, 0, 8, 0},
        {0, 9, 0, 0, 7, 0, 0, 0, 4},
        {0, 8, 2, 0, 4, 0, 0, 0, 6}};

    cout << boolalpha;
    cout << isItSudoku(matrix);
}