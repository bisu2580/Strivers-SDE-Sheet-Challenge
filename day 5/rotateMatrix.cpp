#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int iter = min(m, n);
    for (int i = 0; i < iter / 2; i++)
    {
        int top = i, left = i;
        int right = m - i - 1, bottom = n - i - 1;

        int num = mat[top][left];

        for (int j = left + 1; j <= right; j++)
        {
            swap(mat[top][j], num);
        }
        for (int j = top + 1; j <= bottom; j++)
        {
            swap(mat[j][right], num);
        }
        for (int j = right - 1; j >= left; j--)
        {
            swap(mat[bottom][j], num);
        }
        for (int j = bottom - 1; j >= top; j--)
        {
            swap(mat[j][left], num);
        }
    }
}
int main()
{
    vector<vector<int>> num = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    rotateMatrix(num, 3, 4);
    cout << "Rotated Matrix is \n";
    for (auto i : num)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}