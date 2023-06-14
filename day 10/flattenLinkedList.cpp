#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
}
Node *sortTwoLists(Node *first, Node *second)
{
    Node *temp = first;
    if (first->data > second->data)
    {
        temp = second;
        second = second->child;
    }
    else
    {
        first = first->child;
    }

    Node *ansTail = temp;

    while (first && second)
    {
        if (first->data <= second->data)
        {
            ansTail->child = first;
            first = first->child;
        }
        else if (first->data > second->data)
        {
            ansTail->child = second;
            second = second->child;
        }
        ansTail = ansTail->child;
    }

    if (!first)
        ansTail->child = second;
    else
        ansTail->child = first;

    return temp;
}
Node *flattenLinkedList(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *temp = head->next;
    head->next = NULL;
    temp = flattenLinkedList(temp);
    head = sortTwoLists(head, temp);
    return head;
}
int main()
{
    Node *list1 = new Node(1);
    Node *list2 = new Node(2);
    Node *list3 = new Node(3);
    Node *list4 = new Node(4);

    Node *list5 = new Node(5);
    Node *list6 = new Node(6);

    Node *list7 = new Node(11);
    Node *list8 = new Node(14);
    Node *list9 = new Node(15);

    Node *list10 = new Node(13);
    Node *list11 = new Node(27);
    Node *list12 = new Node(28);
    Node *list13 = new Node(45);

    list1->next = list5;
    list5->next = list7;
    list7->next = list10;

    list1->child = list2;
    list2->child = list3;
    list3->child = list4;

    list5->child = list6;

    list7->child = list8;
    list8->child = list9;

    list10->child = list11;
    list11->child = list12;
    list12->child = list13;

    Node *head = flattenLinkedList(list1);
    print(head);
}