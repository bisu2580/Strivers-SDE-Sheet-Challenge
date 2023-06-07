#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int topIndex;
    int capacity;

    Stack(int size)
    {
        arr = new int[size];
        topIndex = -1;
        capacity = size;
    }

    void push(int num)
    {
        if (isFull())
            return;
        else
        {
            topIndex++;
            arr[topIndex] = num;
        }
    }

    int pop()
    {
        int temp;
        if (isEmpty())
        {
            temp = -1;
        }
        else
        {
            temp = arr[topIndex];
            topIndex--;
        }
        return temp;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return arr[topIndex];
    }

    int isEmpty()
    {
        return (topIndex == -1);
    }

    int isFull()
    {
        return topIndex >= capacity - 1;
    }
};
void print(Stack s)
{
    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    print(s);
    s.pop();
    s.pop();
    s.pop();
    print(s);
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
}