#include <bits/stdc++.h>
using namespace std;
int longestSubSeg(vector<int> &arr, int n, int k)
{
    int zeros = 0;
    int left = 0;
    int maxLength = 0;

    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
            zeros++;
        while (zeros > k)
        {
            if (arr[left] == 0)
                zeros--;
            left++;
        }
        maxLength = max(maxLength, r - left + 1);
    }
    return maxLength;
}
int main()
{
    vector<int> arr = {1, 0, 1, 1, 0, 0, 1, 1, 1};
    cout << longestSubSeg(arr, arr.size(), 2);
}