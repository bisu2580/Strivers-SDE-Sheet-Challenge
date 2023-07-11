#include <bits/stdc++.h>
using namespace std;
long long getTrappedWater(long long *arr, int n)
{
    long long lmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = max(arr[i], lmax[i - 1]);
        lmax[i] = temp;
    }

    long long rmax[n];
    rmax[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int temp = max(arr[i], rmax[i + 1]);
        rmax[i] = temp;
    }
    long long water = 0;
    for (int i = 1; i < n - 1; i++)
    {
        water = water + (min(lmax[i], rmax[i]) - arr[i]);
    }
    return water;
}
int main()
{
    long long arr[] = {3, 0, 0, 2, 0, 4};
    int size = 6;
    cout << getTrappedWater(arr, size);
}