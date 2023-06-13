#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    vector<int> arr;
    int Front, Rear;
    Queue()
    {
        Front = 0;
        Rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return Front == Rear;
    }

    void enqueue(int data)
    {
        arr.push_back(data);
        Rear++;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        int popped = arr[Front];
        Front++;
        return popped;
    }

    int front()
    {
        if (isEmpty())
            return -1;
        return arr[Front];
    }
};
int main()
{
    Queue q;
    q.enqueue(17);
    q.enqueue(23);
    q.enqueue(11);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}