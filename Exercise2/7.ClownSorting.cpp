#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int cnt = 0;
    while (cin >> n)
    {
        cin.ignore(); // 忽略换行符
        cnt++;
        if(n==0)
            return 0;
        vector<string> a;
        vector<string> b;
        for (int i = 0; i < n; i++)
        {
            string input;
            getline(cin, input); // 读取输入
            if (i % 2 == 0)
            {
                a.push_back(input);
            }
            else
            {
                b.push_back(input);
            }
        }
        cout << "set-" << cnt << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << endl;
        }
        for (int i = b.size() - 1; i >= 0; i--)
        {
            cout << b[i] << endl;
        }
    }
}