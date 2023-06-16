#include <bits/stdc++.h>
using namespace std;
int findPivot(int *arr, int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= arr[0])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
int binarySearch(int *arr, int key, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (key == arr[mid])
            return mid;

        else if (key > arr[mid])
            start = mid + 1;

        else
            end = mid - 1;
    }
    return -1;
}
int search(int *arr, int n, int key)
{
    int pivot = findPivot(arr, n);
    int left = 0;
    int right = n - 1;

    if (key >= arr[pivot] && key <= arr[right])
    {
        return binarySearch(arr, key, pivot, right);
    }
    return binarySearch(arr, key, left, pivot - 1);
}
int main()
{
    int arr[] = {4, 5, 1, 2, 3};
    cout << search(arr, 5, 3);
}