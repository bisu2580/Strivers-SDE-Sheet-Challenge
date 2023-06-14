#include <bits/stdc++.h>
using namespace std;
class Queue
{
    // Define the data members(if any) here.
    stack<int> s1, s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        int poppedElement = -1;
        if (isEmpty())
            return poppedElement;
        if (!s2.empty())
        {
            poppedElement = s2.top();
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            poppedElement = s2.top();
            s2.pop();
        }
        return poppedElement;
    }

    int peek()
    {
        // Implement the peek() function here.
        int poppedElement = -1;
        if (isEmpty())
            return poppedElement;

        if (!s2.empty())
        {
            poppedElement = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            poppedElement = s2.top();
        }
        return poppedElement;
    }

    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }
    void print()
    {
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
    }
};
int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(30);
    q.enQueue(20);
    q.print();
}