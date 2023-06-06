#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
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
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *removeKthNode(Node *head, int K)
{
    int total = countNodes(head);
    if (!head || K <= 0 || K > total)
        return NULL;

    if (K == total)
    {
        Node *t = head;
        head = head->next;
        delete t;
        return head;
    }

    Node *temp = head;
    Node *prev;

    for (int i = 0; i < total - K; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev->next)
    {
        prev->next = temp->next;
        delete temp;
    }
    return head;
}
int main()
{
    Node *head = new Node(23);
    Node *second = new Node(24);
    Node *third = new Node(13);
    Node *forth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = forth;
    head = removeKthNode(head, 2);
    print(head);
}