#include <bits/stdc++.h>
using namespace std;
string reverseString(string &str)
{
    stack<string> st;
    for (int i = 0; i < str.size(); i++)
    {
        string temp = "";
        while (str[i] != ' ' && i < str.size())
        {
            temp += str[i];
            i++;
        }
        if (!temp.empty())
        {
            st.push(temp);
        }
    }
    str = "";
    while (!st.empty())
    {
        str += st.top();
        str += ' ';
        st.pop();
    }
    return str;
}
int main()
{
    string num = "Welcome  to Coding Ninjas";
    num = reverseString(num);
    cout << num.data();
}