#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, P1, P2, P3, T1, T2;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2; // 输入n, P1, P2, P3, T1, T2
    vector<int> times(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> times[i]; // 输入每个时间点
    }
    // 输入数据已经有序
    int totalEnergy = 0; // 总能量消耗

    // 直接计算相邻两个时间点之间消耗的电量
    // 如果下标为偶数则为开始时间，如果下标为奇数则为结束时间
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int start = times[i];
        int end = times[i + 1];
        int duration = end - start; // 计算时间段长度

        if (i % 2 == 0) // 如果开始时间为偶数则当前处理时间段为工作时间
        {
            totalEnergy += P1 * duration; // 工作时间消耗P1单位能量
        }
        else // 如果开始时间为奇数则当前处理时间段为休息时间，判断时间长度并进行计算
        {
            if(duration <=T1)
            {
                totalEnergy += P1 * duration;// 休息时间小于等于T1则消耗P1单位能量
            }
            else if(duration<=T1+T2)
            {
                totalEnergy+=P1*T1+P2*(duration-T1);// 休息时间大于T1小于等于P1+P2则消耗P1*T1+P2*(duration-T1)单位能量
            }
            else
            {
                totalEnergy += P1 * T1 + P2 * T2 + P3 * (duration - T1 - T2);// 休息时间大于T1小于等于P1+P2+P3则消耗P1*T1+P2*T2+P3*(duration-T1-T2)单位能量
            }
        }
    }
    cout << totalEnergy << endl;
}