#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> position(n); // 跑者起始位置
    vector<int> speed(n);    // 跑者速度
    // 读入所有跑者的位置
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
    }
    // 读入所有跑者的速度
    for (int i = 0; i < n; i++)
    {
        cin >> speed[i];
    }
    int zeroPatient = k - 1;        // 初始感染者编号（下标从0开始）
    int s0 = position[zeroPatient]; // 初始感染者位置
    int v0 = speed[zeroPatient];    // 初始感染者速度

    // 找到左侧最大速度和右侧最小速度（包括源头）
    int vmax = v0, vmin = v0;
    for (int i = 0; i < n; i++)
    {
        if (position[i] <= s0)
            vmax = max(vmax, speed[i]); // 左侧最大速度
        if (position[i] >= s0)
            vmin = min(vmin, speed[i]); // 右侧最小速度
    }

    // 统计安全人数（不会被感染的人数）
    int safe = 0;
    for (int i = 0; i < n; i++)
    {
        // 左侧：速度小于右侧最小速度的人安全
        if (position[i] < s0)
        {
            if (speed[i] < vmin)
                safe++;
            else if (speed[i] == vmin && position[i] < s0)
                safe++;
        }
        // 右侧：速度大于左侧最大速度的人安全
        if (position[i] > s0)
        {
            if (speed[i] > vmax)
                safe++;
            else if (speed[i] == vmax && position[i] > s0)
                safe++;
        }
    }
    // 输出感染人数
    cout << (n - safe) << endl;
    return 0;
}