#include <bits/stdc++.h>
using namespace std;
void recursion(vector<int> &v, int index, vector<int> &temp,
               vector<vector<int>> &ans)
{

    if (index >= v.size())
    {
        ans.push_back(temp);
        return;
    }

    temp.push_back(v[index]);
    recursion(v, index + 1, temp, ans);
    temp.pop_back();

    recursion(v, index + 1, temp, ans);
}
vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    recursion(v, index, temp, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = pwset(nums);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}