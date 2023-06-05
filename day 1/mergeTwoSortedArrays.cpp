#include <bits/stdc++.h>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> ansArray;
    int i = 0, j = 0;
    int ansIndex = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            ansArray.push_back(arr1[i]);
            i++;
        }
        else
        {
            ansArray.push_back(arr2[j]);
            j++;
        }
    }
    while (i < m)
    {
        ansArray.push_back(arr1[i]);
        i++;
    }
    while (j < n)
    {
        ansArray.push_back(arr2[j]);
        j++;
    }
    arr1.clear();
    arr1 = ansArray;
    return arr1;
}
int main()
{
    vector<int> arr1 = {3, 4, 56, 78};
    vector<int> arr2 = {45, 46, 67, 89};
    vector<int> ans = ninjaAndSortedArrays(arr1, arr2, arr1.size(), arr2.size());
    cout << "Merged Array:\n";
    for (auto j : ans)
    {
        cout << j << " ";
    }
}