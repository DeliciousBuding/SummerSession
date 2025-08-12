#include <iostream>

using namespace std;

struct e
{
    int A;
    int B;
    int C;
};

void cal(e x, e y)
{
    int rx = 0, ry = 0;
    rx = (-x.C * y.B + x.B * y.C) / (x.A * y.B - x.B * y.A);
    ry = (-x.A * y.C + x.C * y.A) / (x.A * y.B - x.B * y.A);
    cout << rx << " " << ry << " ";
}

int main()
{
    int N = 0;

    cin >> N;
    e *all = new e[N];
    // 接下来 N 行，每行包含A、B、C三个整数，表示一个形如“Ax+By+C=0”形式的二元一次方程。
    for (int i = 0; i < N; i++)
        cin >> all[i].A >> all[i].B >> all[i].C;
    for (int i = 0; i < N - 1; i++) // 两两组合求解
    {
        for (int j = i + 1; j < N; j++)
            cal(all[i], all[j]);
        cout << endl;
    }
    return 0;
}



// 2.Museum
#include <bits/stdc++.h>
using namespace std;
const int N = 100000007;
long long dp[1000010];

int main()
{
    std::ios::sync_with_stdio(0);
    int n, a, b;
    long long s;
    cin >> n >> s >> a >> b;
    int maxSum = n * (n - 1) / 2;

    dp[0] = 1;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = (i + 1) * i / 2; j >= i; --j)
        {
            dp[j] += dp[j - i];
            dp[j] %= N;
        }
    }

    long long low = -maxSum * (long long)a + s;

    int cnt = 0;
    long long f = low % n;
    long long q = (a + b) % n;

    for (int i = 0; i <= maxSum; i++)
    {
        if (((long long)i * q + f) % (long long)n == 0)
        {
            cnt += dp[i];
            cnt = cnt % N;
        }
    }
    cout << cnt;
    return 0;
}