#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1e7 + 10;
long long position[MAXSIZE], speed[MAXSIZE];

int main()
{
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> position[i];
    for (int i = 1; i <= n; i++)
        cin >> speed[i];

    long long s0 = position[k], v0 = speed[k];
    long long max_v = v0, min_v = v0;
    // 找到左侧最大速度和右侧最小速度（包括源头）
    for (int i = 1; i <= n; i++)
    {
        if (position[i] <= s0)
            max_v = max(max_v, speed[i]);
        if (position[i] >= s0)
            min_v = min(min_v, speed[i]);
    }

    int safe = 0;
    for (int i = 1; i <= n; i++)
    {
        if (position[i] < s0)
        {
            if (speed[i] < min_v)
                safe++;
            else if (speed[i] == min_v && position[i] < s0)
                safe++;
        }
        if (position[i] > s0)
        {
            if (speed[i] > max_v)
                safe++;
            else if (speed[i] == max_v && position[i] > s0)
                safe++;
        }
    }
    cout << (n - safe) << endl;
    return 0;
}