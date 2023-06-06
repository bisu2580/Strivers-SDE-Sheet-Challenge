#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        maxi = max(maxi, sum);
    }
    return maxi;
}
int main()
{
    int arr[] = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    cout << "Maximum Subarray sum is " << maxSubarraySum(arr, 9);
}