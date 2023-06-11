#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
void print(Node<int> *first)
{
    Node<int> *temp = first;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    Node<int> *temp = first;
    if (second->data < first->data)
    {
        temp = second;
    }
    Node<int> *ansHead = NULL;
    Node<int> *ansTail = ansHead;

    if (temp == first)
    {
        ansHead = temp;
        ansTail = ansHead;
        first = first->next;
    }
    else
    {
        ansHead = temp;
        ansTail = ansHead;
        second = second->next;
    }
    while (first && second)
    {
        if (first->data < second->data)
        {
            ansTail->next = new Node<int>(first->data);
            ansTail = ansTail->next;
            first = first->next;
        }
        else
        {
            ansTail->next = new Node<int>(second->data);
            ansTail = ansTail->next;
            second = second->next;
        }
    }
    while (first)
    {
        ansTail->next = new Node<int>(first->data);
        ansTail = ansTail->next;
        first = first->next;
    }
    while (second)
    {
        ansTail->next = new Node<int>(second->data);
        ansTail = ansTail->next;
        second = second->next;
    }
    return ansHead;
}
int main()
{
    Node<int> *first = new Node<int>(1);
    Node<int> *second = new Node<int>(8);
    Node<int> *third = new Node<int>(10);
    Node<int> *forth = new Node<int>(24);
    Node<int> *fifth = new Node<int>(25);
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    Node<int> *first1 = new Node<int>(5);
    Node<int> *second1 = new Node<int>(6);
    Node<int> *third1 = new Node<int>(35);
    first->next = second;
    second->next = third;

    Node<int> *head = sortTwoLists(first, first1);
    print(head);
}