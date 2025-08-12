#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int input;
    int num[10] = {0};
    int cnt = 0;
    while (cin >> input)
    {
        num[input]++;
        cnt++;
    }
    for (int i = 0; i < cnt; i++)
    {
        if (i == 0) // 判断首数字，不能为0
        {
            for (int j = 1; j < 10; j++)
            {
                if (num[j] != 0)
                {
                    cout << j;
                    num[j]--;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < 10; j++)
            {
                if (num[j] != 0)
                {
                    cout << j;
                    num[j]--;

                    break;
                }
            }
        }
    }
    return 0;
}
