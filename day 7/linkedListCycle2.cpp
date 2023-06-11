#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
void print(Node *first)
{
    Node *temp = first;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *firstNode(Node *head)
{

    bool cycle = false;
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cycle = true;
            break;
        }
    }

    if (!cycle)
        return NULL;

    slow = head;
    if (fast->next == head)
        return 0;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main()
{
    Node *first = new Node(1);
    Node *second = new Node(8);
    Node *third = new Node(10);
    Node *forth = new Node(24);
    Node *fifth = new Node(25);
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = second;
    Node *head = firstNode(first);
    cout << "First Node has value " << head->data;
}