#include <bits/stdc++.h>
using namespace std;
void buildFactorial(int n, int &fact, vector<int> &num)
{
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        num.push_back(i);
    }
    num.push_back(n);
}
string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    buildFactorial(n, fact, numbers);
    string ans = "";
    k -= 1;
    while (true)
    {
        int block = k / fact;
        ans += (numbers[block] + '0');
        numbers.erase(numbers.begin() + block);
        if (numbers.size() == 0)
            break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
int main()
{
    cout << kthPermutation(3, 2).data();
}