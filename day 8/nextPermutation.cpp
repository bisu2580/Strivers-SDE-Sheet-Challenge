#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int> &arr, int n)
{
    int index = -1;
    // Finding breakpoint index
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    // Finding out next greater of arr[index]
    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}
int main()
{
    vector<int> arr = {1, 4, 2, 3, 5};
    arr = nextPermutation(arr, arr.size());
    for (auto i : arr)
    {
        cout << i << " ";
    }
}