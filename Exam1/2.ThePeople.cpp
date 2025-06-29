#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> time(n), score(n);
    vector<bool> isAffected(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i] >> score[i];
    }

    // 判断每个人是否被激励
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (time[j] <= time[i] && score[j] >= score[i] && !(time[j] == time[i] && score[j] == score[i]))
            {
                isAffected[i] = true;
                break;
            }
        }
    }

    // 输出未受影响的id（从1开始）
    for (int i = 0; i < n; i++)
    {
        if (!isAffected[i])
            cout << i + 1 << endl;
    }
}
