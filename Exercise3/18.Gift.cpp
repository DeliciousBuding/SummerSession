#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    while (cin >> input)
    {
        int cnt = 0; // 当前发现左括号的个数
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == 'B')
            {
                cout << cnt << endl;
                break;
            }
            if (input[i] == '(')
            {
                cnt++;
            }
            if (input[i] == ')')
            {
                cnt--;
            }
        }
    }
}