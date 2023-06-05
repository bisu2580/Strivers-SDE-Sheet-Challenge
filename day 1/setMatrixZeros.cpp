#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{ 
    set<int> rowSet;
    set<int> colSet;

    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowSet.insert(i);
                colSet.insert(j);
            }
        }
    }
    for (auto k : rowSet)
    {
        for (int i = 0; i < col; i++)
        {
            matrix[k][i] = 0;
        }
    }
    for (auto k : colSet)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][k] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{7, 19, 9}, {4, 21, 0}};
    setZeros(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}