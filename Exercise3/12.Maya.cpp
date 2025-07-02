#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> HaabMonth({"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"});
    vector<string> TzolkinDay({"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"});
    for (int i = 0; i < n; i++)
    {
        string DayMonth;
        int Year;
        cin >> DayMonth >> Year;
        int point = DayMonth.find('.');
        int Day = stoi(DayMonth.substr(0, point));     // 从0-19
        string MonthName = DayMonth.substr(point + 1); // 共有19个月
        int Month;                                     // 0-17每个月20天 第18月5天
        for (int j = 0; j < 19; j++)
        {
            if (HaabMonth[j] == MonthName)
            {
                Month = j;
                break;
            }
        }
        int days = 365 * Year;
        ; // 从第0天开始的
        if (Month <= 17)
        {
            days += Month * 20 + Day;
        }
        else
        {
            days += 18 * 20 + Day;
        }

        // 得到从第0日开始的数据
        int year = days / (13 * 20);
        int day = days % 13 + 1;
        cout << day << ' ' << TzolkinDay[days%20] << ' ' << year << endl;
    }
}