#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int left = 1;
    int right = n - 2;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];
        if (((mid % 2 == 1) && arr[mid] == arr[mid - 1]) || (mid % 2 == 0) && arr[mid] == arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Single non duplicate element is " << singleNonDuplicate(nums);
}