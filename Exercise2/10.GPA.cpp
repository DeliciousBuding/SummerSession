#include <bits/stdc++.h>
using namespace std;

double getPoint(int a)
{
    if (a >= 90)
        return 4.0;
    else if (a >= 85)
        return 3.7;
    else if (a >= 82)
        return 3.3;
    else if (a >= 78)
        return 3.0;
    else if (a >= 75)
        return 2.7;
    else if (a >= 72)
        return 2.3;
    else if (a >= 68)
        return 2.0;
    else if (a >= 64)
        return 1.5;
    else if (a >= 60)
        return 1.0;
    else
        return 0.0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> credit(n), score(n);
    for (int i = 0; i < n; i++)
        cin >> credit[i];
    for (int i = 0; i < n; i++)
        cin >> score[i];

    double total = 0, sumCredit = 0;
    for (int i = 0; i < n; i++)
    {
        total += getPoint(score[i]) * credit[i];
        sumCredit += credit[i];
    }
    cout << fixed << setprecision(2) << total / sumCredit << endl;
    return 0;
}