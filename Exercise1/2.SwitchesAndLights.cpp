#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> inputLines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputLines[i];
    }

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> cnt(m, 0); // 每盏灯被多少开关控制

    // 转换输入并计算cnt
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = inputLines[i][j] - '0';
            if (a[i][j] == 1)
            {
                cnt[j]++;
            }
        }
    }

    // 检查是否存在可忽略的开关
    for (int i = 0; i < n; i++)
    {
        bool valid = true;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && cnt[j] < 2)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}