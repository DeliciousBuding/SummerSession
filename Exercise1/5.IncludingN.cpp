#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n; // 输入范围和N
    for (int i = 1; i <= m; i++)
    {
        if (i % n == 0) // 如果i能被N整除
        {
            cout << i;       // 输出i
            if (i != m)      // 如果i不是m
                cout << " "; // 输出空格
            continue;
        }
        string s = to_string(i); // 将i转换为字符串
        string t = to_string(n); // 将N转换为字符串
        if (s.find(t) != string::npos) // 如果i的字符串形式包含N的字符串形式
        {
            cout << i;       // 输出i
            if (i != m)      // 如果i不是m
                cout << " "; // 输出空格
            continue;
        }
    }
}