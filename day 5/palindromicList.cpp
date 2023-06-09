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
LinkedListNode<int> *findMiddle(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int size(LinkedListNode<int> *head)
{
    int count = 0;
    LinkedListNode<int> *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
LinkedListNode<int> *rev(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *nxt;
    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head)
{

    int count = size(head);
    if (count <= 1)
        return true;

    LinkedListNode<int> *temp = head;
    LinkedListNode<int> *middle = findMiddle(head);

    LinkedListNode<int> *nxt = middle->next;
    nxt = rev(nxt);
    temp = head;
    while (nxt)
    {
        if (temp->data != nxt->data)
            return false;
        nxt = nxt->next;
        temp = temp->next;
    }
    return true;
}
int main()
{
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    LinkedListNode<int> *second = new LinkedListNode<int>(2);
    LinkedListNode<int> *third = new LinkedListNode<int>(3);
    LinkedListNode<int> *forth = new LinkedListNode<int>(2);
    LinkedListNode<int> *fifth = new LinkedListNode<int>(1);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    if (isPalindrome(head))
    {
        cout << "List is Palindrome\n";
    }
    else
    {
        cout << "List is not Palindrome\n";
    }
}