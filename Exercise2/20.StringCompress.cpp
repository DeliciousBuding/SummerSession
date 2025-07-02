#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    string str;
    cin.ignore();
    getline(cin, str);

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        // 单个字符编码
        dp[i] = dp[i - 1] + a;

        // 检查是否为之前子串的子串
        for (int j = 1; j < i; j++)
        {
            string prefix = str.substr(0, j);     //[0,j]
            string suffix = str.substr(j, i - j); //[j,i-1]
            

            if (prefix.find(suffix) != string::npos)
            {
                dp[i] = min(dp[i], dp[j] + b);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}