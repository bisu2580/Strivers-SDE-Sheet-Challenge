#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &s, int data)
{
    if (s.empty() || s.top() <= data)
    {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, data);
    s.push(temp);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, temp);
}
int main()
{
    stack<int> ans;
    ans.push(10);
    ans.push(1);
    ans.push(19);
    ans.push(9);
    ans.push(38);
    ans.push(48);
    ans.push(-7);
    sortStack(ans);

    cout << "Contents:\n";
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}