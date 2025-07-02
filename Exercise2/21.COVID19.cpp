#include <bits/stdc++.h>
using namespace std;

// 暴力算法

// 事件结构体，表示两名跑者相遇的事件
struct Event
{
    pair<long long, long long> time; // 相遇所需时间（用分数表示，避免精度误差）
    int a, b;                        // 跑者编号
    // 重载小于号，用于事件排序（按时间早晚）
    bool operator<(const Event &other)
    {
        return other.time.second * time.first < time.second * other.time.second;
    }
};

int main()
{
    std::ios::sync_with_stdio(0);
    int n, zeroPatient;
    cin >> n >> zeroPatient;
    vector<int> position(n);       // 跑者起始位置
    vector<int> speed(n);          // 跑者速度
    vector<bool> infected(n, 0);   // 是否感染
    infected[zeroPatient - 1] = 1; // 初始感染者

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

    // 枚举每一对跑者，判断是否可能相遇并发生传染
    vector<Event> events;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int length = position[j] - position[i];
            int speedDiff = speed[j] - speed[i];
            // 如果两人有追赶关系，且速度不同，计算相遇时间
            if (length * speedDiff < 0)
            {
                Event newEvent;
                newEvent.a = i;
                newEvent.b = j;
                newEvent.time.first = abs(length);
                newEvent.time.second = abs(speedDiff);
                events.push_back(newEvent);
            }
            // 如果两人起点重合且速度相同，立即相遇
            if (speedDiff == 0 && length == 0)
            {
                Event newEvent;
                newEvent.a = i;
                newEvent.b = j;
                newEvent.time = {0, 1};
                events.push_back(newEvent);
            }
        }
    }
    // 按相遇时间排序所有事件
    sort(events.begin(), events.end());
    // 依次处理每个事件，模拟病毒传播
    for (auto it : events)
    {
        // 如果a感染b
        if (infected[it.a] && !infected[it.b])
        {
            infected[it.b] = 1;
        }
        // 如果b感染a
        if (infected[it.b] && !infected[it.a])
        {
            infected[it.a] = 1;
        }
    }

    // 统计感染人数
    int cnt = 0;
    for (auto it : infected)
    {
        if (it)
            cnt++;
    }
    cout << cnt - 1; // 输出感染人数（不包括初始感染者）
}