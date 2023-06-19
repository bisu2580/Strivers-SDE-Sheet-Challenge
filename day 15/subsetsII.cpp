#include <bits/stdc++.h>
using namespace std;
void findAns(int index, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);

    for (int i = index; i < arr.size(); i++)
    {

        if (i != index and arr[i] == arr[i - 1])
        {
            continue;
        }

        temp.push_back(arr[i]);
        findAns(i + 1, arr, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<int> temp;
    vector<vector<int>> res;

    sort(arr.begin(), arr.end());

    findAns(0, arr, temp, res);
    return res;
}
int main()
{
    vector<int> arr = {1, 1, 3};
    vector<vector<int>> nums = uniqueSubsets(arr.size(), arr);
    for (auto i : nums)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}