// 第一行包含两个数据n和w(1<=n<=1000, 1<=w<=109)，分别表示车站的数目和公交车可容纳的最大乘客人数。

// 第二行包含一个序列a1,a2,...,an，表示记录仪记录的各站的数据。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> s(n), sum(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sum[0] = 0;
    int Smax = 0, Smin = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + s[i-1];
        Smax = max(Smax, sum[i]);
        Smin = min(Smin, sum[i]);
    }
    int left = max(0, -Smin);
    int right = min(m, m - Smax);
    int ans = right - left + 1;
    if (ans < 0)
        ans = 0;
    cout << ans << endl;
    return 0;
}