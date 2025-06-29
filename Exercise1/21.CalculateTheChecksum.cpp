#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; // 测试用例数
    cin >> T;
    while (T--)
    {
        int B;
        string N;
        cin >> B >> N;

        // 计算各位数字和
        int sum = 0;
        for (int i = 0; i < N.size(); i++)
        {
            if (N[i] >= '0' && N[i] <= '9')
            {
                sum += (N[i] - '0');
            }
            else if (N[i] >= 'a' && N[i] <= 'f')
            {
                sum += (N[i] - 'a' + 10);
            }
        }

        // 计算校验码
        //(sum + digit) % (B-1) = 0

        // 这意味着sum + digit是(B-1)的倍数，可表示为：
        // sum + digit = k(B-1)  (k为某个正整数)

        // digit = k(B - 1) - sum

        // 对两边取模(B-1)
        // digit % (B - 1) = (k(B - 1) - sum) % (B - 1)

        // 因为k(B-1)是(B-1)的倍数，所以k(B-1) % (B-1) = 0：
        // digit % (B-1) = (0 - sum) % (B-1) = (-sum) % (B-1)

        //(-sum) % (B-1) = (B-1) - (sum % (B-1))  (当sum % (B-1) ≠ 0时)
        //(-sum) % (B - 1) = 0(当sum % (B - 1) = 0时)
        
        int checkDigit = 0;
        if (sum % (B - 1) != 0)
        {
            checkDigit = (B - 1) - (sum % (B - 1));
        }

        // 输出校验码
        if (checkDigit < 10)
            cout << checkDigit << endl;
        else
            cout << char(checkDigit - 10 + 'a') << endl;
    }
    return 0;
}