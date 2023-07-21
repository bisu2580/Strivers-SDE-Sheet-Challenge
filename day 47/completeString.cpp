#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    trieNode *child[26];
    bool isEnding;
    trieNode()
    {
        this->isEnding = false;
        for (int i = 0; i < 26; i++)
        {
            this->child[i] = NULL;
        }
    }
    void insert(trieNode *root, string str)
    {
        int len = str.length();
        trieNode *node = root;
        for (int level = 0; level < len; level++)
        {
            int index = str[level] - 'a';
            if (!node->child[index])
            {
                node->child[index] = new trieNode();
            }
            node = node->child[index];
        }
        node->isEnding = true;
    }
    bool allArePrefix(trieNode *root, string &word)
    {
        trieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            node = node->child[index];
            if (!node || !node->isEnding)
                return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    string ans = "";
    trieNode *root = new trieNode();
    for (string word : a)
    {
        root->insert(root, word);
    }
    for (string word : a)
    {
        if (!root->allArePrefix(root, word))
            continue;
        if (ans.size() < word.size())
        {
            ans = word;
        }
        else if (ans.size() == word.size() && word < ans)
        {
            ans = word;
        }
    }
    if (!ans.size())
        ans = "None";
    return ans;
}
int main()
{
    vector<string> ans = {"ab", "abc", "a", "bp"};
    cout << completeString(4, ans).data();
}