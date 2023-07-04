#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *arr[26];
    bool contains(char ch)
    {
        return arr[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }
};
int distinctSubstring(string &word)
{
    int count = 0;
    Node *root = new Node();
    for (int i = 0; i < word.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < word.size(); j++)
        {
            if (!node->contains(word[j]))
            {
                count++;
                node->put(word[j], new Node());
            }
            node = node->get(word[j]);
        }
    }
    return count;
}
int main()
{
    string s = "abcd";
    cout << distinctSubstring(s) << endl;
}