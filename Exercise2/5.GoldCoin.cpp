#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int sum = 0;
        int cnt = 1;
        int day = 0;
        for (int i = 1; i <= n; i++)
        {
            if (day == cnt)
            {
                day = 1;
                cnt++;
            }
            else
            {
                day++;
            }
            sum += cnt;
        }
        cout << n << ' ' << sum << endl;
    }
}