#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    if (!firstHead || !secondHead)
        return NULL;

    int firstCount = 0;
    int secondCount = 0;
    Node *temp = firstHead;

    while (temp)
    {
        firstCount++;
        temp = temp->next;
    }

    temp = secondHead;
    while (temp)
    {
        secondCount++;
        temp = temp->next;
    }

    if (firstCount > secondCount)
    {
        for (int i = 0; i < (firstCount - secondCount); i++)
        {
            firstHead = firstHead->next;
        }
    }
    else if (secondCount > firstCount)
    {
        for (int i = 0; i < (secondCount - firstCount); i++)
        {
            secondHead = secondHead->next;
        }
    }

    while (firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return firstHead;
}
int main()
{
    Node *first = new Node(4);
    Node *second = new Node(1);
    Node *third = new Node(5);

    Node *forth = new Node(6);
    Node *fifth = new Node(8);

    first->next = second;
    third->next = forth;

    second->next = fifth;
    forth->next = fifth;
    cout << "Intersection Node: " << findIntersection(first, third)->data;
}