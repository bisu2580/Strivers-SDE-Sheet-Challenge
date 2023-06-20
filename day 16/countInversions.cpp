#include <bits/stdc++.h>
using namespace std;
long long merge(long long *arr, long long *temp, long long left, long long mid, long long right)
{
    long long i, j, k;
    long long count = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return count;
}
long long mergeSort(long long *arr, long long left, long long right, long long *temp)
{
    long long mid;
    long long count = 0;
    if (left < right)
    {

        mid = (left + right) / 2;
        count += mergeSort(arr, left, mid, temp);
        count += mergeSort(arr, mid + 1, right, temp);

        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}
long long getInversions(long long *arr, int n)
{
    long long left = 0;
    long long right = n - 1;
    long long temp[n];
    return mergeSort(arr, left, right, temp);
}
int main()
{
    long long nums[] = {2, 5, 1, 3, 4};
    long long ans = getInversions(nums, 5);
    cout << ans;
}