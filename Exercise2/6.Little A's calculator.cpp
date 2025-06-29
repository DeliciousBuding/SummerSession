#include <bits/stdc++.h>
using namespace std;

int getNum(char a)
{
    return a - 'a';
}

char getChar(int a)
{
    return a + 'a';
}

int main()
{
    int n;
    cin >> n;
    for (int t = 0; t < n; t++)
    {
        string A, B;
        cin >> A >> B;

        int lengthA = A.length();
        int lengthB = B.length();
        int maxLength = max(lengthA, lengthB);

        vector<int> result(maxLength + 1, 0);

        // 从低位到高位相加
        for (int i = 0; i < maxLength; i++)
        {
            int a = (lengthA - 1 - i >= 0) ? getNum(A[lengthA - 1 - i]) : 0;
            int b = (lengthB - 1 - i >= 0) ? getNum(B[lengthB - 1 - i]) : 0;
            result[maxLength - i] += a + b;
            if (result[maxLength - i] > 25)
            {
                result[maxLength - i] -= 26;
                result[maxLength - i - 1] += 1;
            }
        }

        // 处理进位溢出
        for (int i = maxLength; i > 0; i--)
        {
            if (result[i] > 25)
            {
                result[i] -= 26;
                result[i - 1] += 1;
            }
        }

        // 输出结果，去除前导0（即'a'）
        bool foundNonZero = false;
        for (int i = 0; i <= maxLength; i++)
        {
            if (!foundNonZero && result[i] == 0)
                continue;
            foundNonZero = true;
            cout << getChar(result[i]);
        }
        if (!foundNonZero)
            cout << 'a'; // 如果结果全为0，输出'a'
        cout << endl;
    }
}