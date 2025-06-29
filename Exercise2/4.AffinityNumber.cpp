#include <bits/stdc++.h>
using namespace std;

int getSum(int a)
{
    int sum = 0;
    for (int i = 1; i <= a / 2; i++)
    {
        if (a % i == 0 && i != a)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int sumA = getSum(a);
        int sumB = getSum(b);
        if (sumA == b && sumB == a)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}