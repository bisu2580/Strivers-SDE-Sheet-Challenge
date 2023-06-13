#include <bits/stdc++.h>
using namespace std;
vector<int> findSpans(vector<int> &price)
{
    vector<int> ans(price.size());
    stack<pair<int, int>> s;

    for (int i = 0; i < price.size(); i++)
    {
        int count = 1;
        int value = price[i];
        while (!s.empty() && s.top().first <= value)
        {
            count += s.top().second;
            s.pop();
        }
        ans[i] = count;
        s.push({value, count});
    }
    return ans;
}
int main()
{
    vector<int> nums = {100, 80, 60, 70, 60, 75, 85};
    nums = findSpans(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}