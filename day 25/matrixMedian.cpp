#include <bits/stdc++.h>
using namespace std;
int smallerThanEqualToMid(vector<int> row, int mid)
{
    int low = 0;
    int high = row.size() - 1;

    while (low <= high)
    {
        int md = low + (high - low) / 2;
        if (row[md] <= mid)
            low = md + 1;
        else
            high = md - 1;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    int low = 1;
    int high = 100;

    int n = matrix.size();
    int m = matrix[0].size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += smallerThanEqualToMid(matrix[i], mid);
        }
        if (count <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    vector<vector<int>> nums = {{2, 6, 9}, {1, 5, 11}, {3, 7, 8}};
    cout << "The median is: ";
    cout << getMedian(nums);
}