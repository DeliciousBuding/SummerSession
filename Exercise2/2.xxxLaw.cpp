#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        int input;
        cin >> input;
        if (input == 0)
        {
            break; // 输入0时退出循环
        }

        int cnt = 0;
        while (input != 1)
        {
            if (input % 2 == 0)
                input /= 2;
            else
                input = (input * 3 + 1) / 2;

            cnt++;
        }
        cout << cnt << endl;
    }
}