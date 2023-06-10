#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int value = arr[i];

        while (s.top() != -1 && s.top() <= value)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(value);
    }
    return ans;
}
int main()
{
    vector<int> ans = {2, 1, 4, 3};
    ans = nextGreater(ans, ans.size());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}