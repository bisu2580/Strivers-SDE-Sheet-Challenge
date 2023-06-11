#include <bits/stdc++.h>
using namespace std;
class minStack
{
    vector<pair<int, int>> v;

public:
    // Constructor
    minStack()
    {
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        pair<int, int> res;
        int minTillIndex;
        if (v.size() == 0)
        {
            res.first = num;
            res.second = num;
            v.push_back(res);
        }
        else
        {
            pair<int, int> res;
            res.first = num;
            res.second = min(num, v.back().second);
            v.push_back(res);
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        int ans;
        if (v.size() == 0)
        {
            ans = -1;
        }
        else
        {
            ans = v.back().first;
            v.pop_back();
        }
        return ans;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        int ans;
        if (v.size() == 0)
        {
            ans = -1;
        }
        else
        {
            ans = v.back().first;
        }
        return ans;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        int ans;
        if (v.size() == 0)
        {
            ans = -1;
        }
        else
        {
            ans = v.back().second;
        }
        return ans;
    }
};
int main()
{
    minStack st;
    st.push(10);
    st.push(5);
    st.push(20);
    cout << "Min element is " << st.getMin() << endl;
    cout << "Top element is " << st.top() << endl;
}