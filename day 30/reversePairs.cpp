#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && arr[i] > 2LL * arr[j])
        {
            j++;
        }
        count += (j - mid - 1);
    }
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return 0;
    int mid = (low + high) / 2;
    int inv = mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid + 1, high);
    inv += merge(arr, low, mid, high);
    return inv;
}
int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}
int main()
{
    // your code goes here
    vector<int> vect{50, 21, 9};
    cout << reversePairs(vect, 4) << endl;
}