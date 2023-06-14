#include <bits/stdc++.h>
using namespace std;
class Stack
{
    queue<int> q1, q2;

public:
    Stack()
    {
    }

    int getSize()
    {
        return q1.size();
    }

    bool isEmpty()
    {
        return q1.empty();
    }

    void push(int element)
    {
        q2.push(element);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;

        int popped = q1.front();
        q1.pop();
        return popped;
    }

    int top()
    {
        // Implement the top() function.
        if (isEmpty())
            return -1;

        int popped = q1.front();
        return popped;
    }
    void print()
    {
        queue<int> temp = q1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();
    s.pop();
    s.pop();
    s.print();
    cout << s.top();
}