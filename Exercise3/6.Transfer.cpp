#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string str;
    getline(cin, str);

    vector<int> cnt(10, 0); // 0-9被转换的次数
    for (int i = 0; i < str.length(); i++)
    {
        char a = str[i];
        if (a <= '9' && a >= '0')
        {
            switch (a)
            {
            case '0':
                cout << "(Zero)";
                cnt[0]++;
                break;
            case '1':
                cout << "(One)";
                cnt[1]++;
                break;
            case '2':
                cout << "(Two)";
                cnt[2]++;
                break;
            case '3':
                cout << "(Three)";
                cnt[3]++;
                break;
            case '4':
                cout << "(Four)";
                cnt[4]++;
                break;
            case '5':
                cout << "(Five)";
                cnt[5]++;
                break;
            case '6':
                cout << "(Six)";
                cnt[6]++;
                break;
            case '7':
                cout << "(Seven)";
                cnt[7]++;
                break;
            case '8':
                cout << "(Eight)";
                cnt[8]++;
                break;
            case '9':
                cout << "(Nine)";
                cnt[9]++;
                break;
            }
        }
        else
            cout << a;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << cnt[i];
        if (i != 9)
            cout << ' ';
    }
}