#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        map<string, int> m;
        string str;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            cin >> str;
            m[str]++;
        }
        for (auto &it : m)
        {
            if (it.second % 2 == 1)
            {
                cout << it.first << endl;
                break;
            }
        }
    }
    return 0;
}