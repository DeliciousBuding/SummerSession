#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string A, B;
    int a, b;
    cin >> A >> a >> B >> b;
    int cntA = 0, cntB = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] - '0' == a)
            cntA++;
    }
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] - '0' == b)
            cntB++;
    }

    for (int i = 0; i < cntA;i++)
    {
        sum += a * pow(10, i);
    }
    for (int i = 0; i < cntB; i++)
    {
        sum += b * pow(10, i);
    }

    cout << sum;
}