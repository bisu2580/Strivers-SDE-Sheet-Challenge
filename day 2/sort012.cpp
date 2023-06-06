#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
    int left = 0;
    int right = n - 1;
    int index = 0;
    while (index <= right)
    {
        if (arr[index] == 0)
        {
            swap(arr[left], arr[index]);
            index++;
            left++;
        }
        else if (arr[index] == 2)
        {
            swap(arr[right], arr[index]);
            right--;
        }
        else
        {
            index++;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 2, 1, 2, 1, 2};
    sort012(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}