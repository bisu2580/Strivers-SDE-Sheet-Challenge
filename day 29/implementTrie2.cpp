#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int countPrefix = 0;
    int endsWith = 0;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *getRef(char ch)
    {
        return links[ch - 'a'];
    }
    void increaseEnd()
    {
        endsWith++;
    }
    void increasePrefix()
    {
        countPrefix++;
    }
    void deleteEnd()
    {
        endsWith--;
    }
    void reducePrefix()
    {
        countPrefix--;
    }
    int getEnd()
    {
        return endsWith;
    }
    int getPrefix()
    {
        return countPrefix;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->getRef(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->getRef(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }
    int countWordsStartingWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->getRef(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getPrefix();
    }
    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->getRef(word[i]);
                node->reducePrefix();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};
int main()
{
    Trie trie = Trie();
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("bango");
    cout << "Count of words starting with \"ba\":";
    cout << trie.countWordsStartingWith("ba");
    cout << endl;
}