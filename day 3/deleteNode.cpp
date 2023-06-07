#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(LinkedListNode<int> *node)
{
    LinkedListNode<int> *temp = node;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void deleteNode(LinkedListNode<int> *node)
{
    LinkedListNode<int> *prev;
    while (node->next)
    {
        prev = node;
        node->data = node->next->data;
        node = node->next;
    }
    prev->next = node->next;
    delete node;
}
int main()
{
    LinkedListNode<int> *first = new LinkedListNode<int>(2);
    LinkedListNode<int> *second = new LinkedListNode<int>(5);
    LinkedListNode<int> *third = new LinkedListNode<int>(7);
    LinkedListNode<int> *forth = new LinkedListNode<int>(10);

    first->next = second;
    second->next = third;
    third->next = forth;

    cout << "Before Deleting the list is: ";
    print(first);
    cout << endl;
    deleteNode(third);
    cout << "Before Deleting the list is: ";
    print(first);
}