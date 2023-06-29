#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> s(arr.begin(), arr.end());
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(arr[i] - 1) != s.end())
            continue;
        else
        {
            int count = 0;
            int curr = arr[i];
            while (s.find(curr) != s.end())
            {
                count++;
                curr++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {33, 20, 34, 30, 35};
    cout << lengthOfLongestConsecutiveSequence(nums, nums.size()) << endl;
}