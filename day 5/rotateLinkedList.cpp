#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
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
int len(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *rotate(Node *head, int k)
{
    if (!head || !head->next || k <= 0)
        return head;
    int totalElements = len(head);
    int rotate = k % totalElements;
    if (rotate == 0)
        return head;

    Node *temp = head;
    for (int i = 1; i < totalElements - rotate; i++)
    {
        temp = temp->next;
    }
    Node *ansHead = temp->next;
    temp->next = NULL;
    Node *ansTail = ansHead;
    while (ansTail->next)
    {
        ansTail = ansTail->next;
    }
    ansTail->next = head;
    return ansHead;
}
int main()
{
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, NULL)))));
    int k = 2;
    head = rotate(head, k);
    print(head);
}