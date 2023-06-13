#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nums = {{0, 1}, {0, 0}};
bool knows(int a, int b)
{
    if (nums[a][b] == 0)
        return false;
    return true;
}
int findCelebrity(int n)
{

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (knows(a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    int celeb = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (knows(celeb, i) == true)
            return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (knows(i, celeb) == false && i != celeb)
            return -1;
    }
    return celeb;
}
int main()
{
    cout << findCelebrity(3);
}
