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
void print(LinkedListNode<int> *head){
    LinkedListNode<int> *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
LinkedListNode<int> *rev(LinkedListNode<int> *prev, LinkedListNode<int> *curr)
{
    if (!curr)
        return prev;
    LinkedListNode<int> *nxt = curr->next;
    curr->next = prev;
    return rev(curr, nxt);
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    return rev(NULL, head);
}
int main()
{
    LinkedListNode<int>* head=new LinkedListNode<int>(45);
    LinkedListNode<int>* second=new LinkedListNode<int>(13);
    LinkedListNode<int>* third=new LinkedListNode<int>(46);
    LinkedListNode<int>* forth=new LinkedListNode<int>(21);
    head->next=second;
    second->next=third;
    third->next=forth;
    head=rev(NULL,head);
    print(head);
}