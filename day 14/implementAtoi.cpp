#include <bits/stdc++.h>
using namespace std;
int atoi(string str)
{

    long long index = 0;
    long long n = str.size();

    // bool positive=str[index]=='+';
    bool negative = str[index] == '-';

    // positive==true?index++:index;
    negative == true ? index++ : index;

    double answer = 0;

    for (int i = index; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            answer = (answer * 10) + (str[i] - '0');
        else
            continue;
    }
    if (negative)
        answer *= -1;

    answer = (answer > INT_MAX) ? INT_MAX : answer;
    answer = (answer < INT_MIN) ? INT_MIN : answer;

    return (int)answer;
}
int main()
{
    string s = "#messi10";
    cout << atoi(s);
}