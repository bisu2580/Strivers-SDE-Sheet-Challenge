#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (s.empty())
            return false;
        else
        {
            if (ch == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (ch == ']' && s.top() == '[')
            {
                s.pop();
            }
            else if (ch == '}' && s.top() == '{')
            {
                s.pop();
            }
            else
                return false;
        }
    }
    return s.empty();
}
int main()
{
    string num = "({}})";
    cout << boolalpha;
    cout << isValidParenthesis(num);
}