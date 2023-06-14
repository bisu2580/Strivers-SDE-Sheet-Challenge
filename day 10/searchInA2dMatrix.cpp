#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int target)
{

    int row = mat.size();
    int col = mat[0].size();

    int i = 0;
    int j = col - 1;

    while (i < row && j >= 0)
    {
        if (mat[i][j] == target)
        {
            return true;
        }
        else if (mat[i][j] > target)
        {
            j--;
        }
        else
            i++;
    }
    return false;
}
int main()
{
    vector<vector<int>> nums = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    if (searchMatrix(nums, 6))
    {
        cout << "Present";
    }
    else
    {
        cout << "Absent";
    }
}