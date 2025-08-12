#include<bits/stdc++.h>
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