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
        this->next = NULL;
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
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *addTwoNumbers(Node *num1, Node *num2)
{

    Node *firstNode = num1;
    Node *secNode = num2;

    Node *ansHead = new Node();
    Node *ansTail = ansHead;
    int carry = 0;

    while (firstNode && secNode)
    {
        int sum = firstNode->data + secNode->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newHead = new Node(digit);
        if (!ansHead)
        {
            ansHead = newHead;
            ansTail = ansTail->next;
        }
        else
        {
            ansTail->next = newHead;
            ansTail = newHead;
        }
        firstNode = firstNode->next;
        secNode = secNode->next;
    }
    while (firstNode)
    {
        int sum = firstNode->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newHead = new Node(digit);
        ansTail->next = newHead;
        ansTail = newHead;
        firstNode = firstNode->next;
    }
    while (secNode)
    {
        int sum = secNode->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newHead = new Node(digit);
        ansTail->next = newHead;
        ansTail = newHead;
        secNode = secNode->next;
    }
    while (carry)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newHead = new Node(digit);
        ansTail->next = newHead;
        ansTail = newHead;
    }
    return ansHead->next;
}
int main()
{
    Node *num1 = new Node(2,NULL);
    Node *num2 = new Node(9, new Node(9,NULL));
    Node *ans = addTwoNumbers(num1, num2);
    cout << "After addition,linked list is \n";
    print(ans);
}