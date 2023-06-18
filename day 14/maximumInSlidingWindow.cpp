#include <bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq;
    vector<int> ans;
    // First window
    for (int i = 0; i < k; i++)
    {
        // small element remove
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // insert current element
        dq.push_back(i);
    }

    // store ans of first window
    ans.push_back(nums[dq.front()]);

    // Remaining window
    for (int i = k; i < nums.size(); i++)
    {
        // remove out of window element
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // small elements remove
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // insert current element
        dq.push_back(i);

        // current window ans store
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 2, 1, 4, 4};
    int ans = 2;
    nums = slidingWindowMaximum(nums, ans);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}