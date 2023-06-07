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
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
// Method 1 (in place)
bool detectCycle(Node *head)
{
    if (!head || !head->next)
        return false;

    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
// Method 2(Using extra space)
bool detectCycle2(Node *head)
{
    if (!head || !head->next)
        return false;
    map<Node *, bool> mp;
    Node *temp = head;
    while (temp)
    {
        if (mp[temp])
            return true;
        mp[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = second;

    cout << boolalpha << detectCycle(first);
}