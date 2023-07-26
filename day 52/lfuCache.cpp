#include <bits/stdc++.h>
using namespace std;
class LFUCache
{
public:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyVal;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

    void update(int key)
    {
        int currFreq = keyVal[key].second;
        freqList[currFreq].erase(pos[key]);
        keyVal[key].second++;

        currFreq = keyVal[key].second;
        freqList[currFreq].push_back(key);

        auto keyPos = freqList[currFreq].end();
        pos[key] = --keyPos;

        if (freqList[minFreq].empty())
        {
            minFreq++;
        }
    }
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }
    int get(int key)
    {
        if (keyVal.find(key) == keyVal.end())
        {
            return -1;
        }
        update(key);
        return keyVal[key].first;
    }
    void put(int key, int value)
    {
        if (capacity == 0)
            return;
        if (keyVal.find(key) != keyVal.end())
        {
            keyVal[key].first = value;
            update(key);
            return;
        }
        if (keyVal.size() == capacity)
        {
            int to_be_deleted = freqList[minFreq].front();
            keyVal.erase(to_be_deleted);
            pos.erase(to_be_deleted);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};
int main()
{
    LFUCache *f = new LFUCache(5);
    f->put(4, 1);
    cout << f->get(2) << endl;
    cout << f->get(4) << endl;
}