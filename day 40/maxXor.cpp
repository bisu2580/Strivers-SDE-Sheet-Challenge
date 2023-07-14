#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie *next[2];
    Trie()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};
class TrieNode
{
private:
    Trie *root;

public:
    TrieNode()
    {
        root = new Trie();
    }
    void insert(int num)
    {
        Trie *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (curr->next[bit] == NULL)
            {
                curr->next[bit] = new Trie();
            }
            curr = curr->next[bit];
        }
    }
    int max_xor(int num)
    {
        Trie *curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (curr->next[!bit])
            {
                ans += (1 << i);
                curr = curr->next[!bit];
            }
            else
            {
                curr = curr->next[bit];
            }
        }
        return ans;
    }
};
int maximumXor(vector<int> A)
{
    int maxi = 0;
    int n = A.size();
    TrieNode *t = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        t->insert(A[i]);
        maxi = max(maxi, t->max_xor(A[i]));
    }
    return maxi;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << maximumXor(nums) << endl;
}