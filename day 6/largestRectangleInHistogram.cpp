#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmallerIndex(vector<int> &height)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(height.size());

    for (int i = 0; i < height.size(); i++)
    {
        int value = height[i];
        while (s.top() != -1 && height[s.top()] >= value)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextSmallerIndex(vector<int> &height)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(height.size());

    for (int i = height.size() - 1; i >= 0; i--)
    {
        int value = height[i];
        while (s.top() != -1 && height[s.top()] >= value)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}
int largestRectangle(vector<int> &heights)
{

    vector<int> prevArray = prevSmallerIndex(heights);
    vector<int> nextArray = nextSmallerIndex(heights);

    int maxi = INT_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        if (nextArray[i] == -1)
            nextArray[i] = heights.size();
        int breadth = nextArray[i] - prevArray[i] - 1;
        maxi = max(maxi, length * breadth);
    }
    return maxi;
}
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Maximum Height: " << largestRectangle(heights);
}