#include <bits/stdc++.h>
using namespace std;
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> nums(n + 1, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        nums[arr[i]]++;
    }
    int missing = -1;
    int repeating = -1;

    for (int i = 1; i <= n; i++)
    {
        if (nums[i] > 1)
            repeating = i;
        else if (nums[i] == 0)
            missing = i;
    }
    return {missing, repeating};
}
int main()
{
    vector<int> nums = {6, 4, 3, 5, 5, 1};
    pair<int, int> ans = missingAndRepeating(nums, nums.size());
    cout<<"Missing Number: "<<ans.first<<endl;
    cout<<"Repeating Number: "<<ans.second<<endl;
}