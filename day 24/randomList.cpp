#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(LinkedListNode<int> *root)
{
    LinkedListNode<int> *temp = root;
    while (temp)
    {
        cout << "data: " << temp->data << " "
             << "Random: " << temp->random->data << endl;
        temp = temp->next;
    }
}
LinkedListNode<int> *ans(LinkedListNode<int> *head)
{
    if (!head)
        return NULL;
    LinkedListNode<int> *temp = head;
    // Duplicate the nodes
    while (temp)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // Change random pointers
    temp = head;
    while (temp)
    {
        LinkedListNode<int> *newNode = temp->next;
        newNode->random = temp->random ? temp->random->next : NULL;
        temp = temp->next->next;
    }
    // detachment
    temp = head;
    LinkedListNode<int> *clonedHead = temp->next;
    while (temp)
    {
        LinkedListNode<int> *it = temp->next;
        temp->next = temp->next->next;
        if (it->next)
            it->next = it->next->next;
        temp = temp->next;
    }
    return clonedHead;
}
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    return ans(head);
}
int main()
{
    LinkedListNode<int> *head = new LinkedListNode<int>(2);
    LinkedListNode<int> *second = new LinkedListNode<int>(4);
    LinkedListNode<int> *third = new LinkedListNode<int>(2);
    LinkedListNode<int> *forth = new LinkedListNode<int>(3);
    LinkedListNode<int> *fifth = new LinkedListNode<int>(5);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    head->random = third;
    second->random = head;
    third->random = forth;

    head = cloneRandomList(head);
}