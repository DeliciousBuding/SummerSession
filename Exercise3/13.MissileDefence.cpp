#include <bits/stdc++.h>
using namespace std;

// 动态规划

int main()
{
    int k;
    cin >> k;
    vector<int> height(k);
    for (int i = 0; i < k; i++)
        cin >> height[i];

    vector<int> dp(k, 1); // dp[i]表示以第i个导弹结尾的最长不升子序列长度
    int ans = 1;
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (height[j] >= height[i]) // j和i比较,j在i前面,如果i能作为j的后缀,则进行计算
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
