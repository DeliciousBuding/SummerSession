#include <bits/stdc++.h>
using namespace std;

string getNextDay(string &s)
{
    if (s == "sunday")
        return "monday";
    else if (s == "monday")
        return "tuesday";
    else if (s == "tuesday")
        return "wednesday";
    else if (s == "wednesday")
        return "thursday";
    else if (s == "thursday")
        return "friday";
    else if (s == "friday")
        return "saturday";
    else
        return "sunday"; // s == "Saturday"
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string begin, end;
        int l, r;
        cin >> begin >> end >> l >> r;
        int sum = 1;
        int ans = 0;
        int find = 0; // 找到的个数
        l--;
        while (l--)   // 跳过l天
        {
            begin = getNextDay(begin); // 获取下一个日期
            sum++;
        }

        while (sum <= r)
        {
            if (begin == end)
            {
                find++;
                ans = sum; // 记录找到的日期
            }
            begin = getNextDay(begin); // 获取下一个日期
            sum++;
        }

        if (find == 0)
        {
            cout << "impossible" << endl;
        }
        if (find == 1)
        {
            cout << ans << endl;
        }
        if (find > 1)
        {
            cout << "many" << endl;
        }
    }
}