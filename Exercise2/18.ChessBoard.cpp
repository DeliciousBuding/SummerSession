#include <bits/stdc++.h>
using namespace std;

// 检查从 (x, y) 开始的 n x n 子矩阵是否为棋盘
bool isBoard(vector<vector<int>> &arr, int x, int y, int n, int N)
{
    if (x + n > N || y + n > N)
        return false; // 检查越界
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 行号和列号从 1 开始，因此用 (i + 1 + j + 1) % 2
            int expected = (i + 1 + j + 1) % 2 == 0 ? 1 : 0;
            if (arr[x + i][y + j] != expected)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));

    // 读取输入，字符 '0' 或 '1' 转换为整数
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = s[j] - '0'; // 将字符转换为整数
        }
    }

    int maxN = 0, cnt = 0;
    // 枚举所有可能的子矩阵大小
    for (int n = 1; n <= N; n++)
    {
        int currentCnt = 0;
        // 枚举所有可能的起点
        for (int i = 0; i <= N - n; i++)
        {
            for (int j = 0; j <= N - n; j++)
            {
                if (isBoard(arr, i, j, n, N))
                {
                    currentCnt++;
                }
            }
        }
        // 更新最大尺寸和计数
        if (currentCnt > 0)
        {
            if (n > maxN)
            {
                maxN = n;
                cnt = currentCnt;
            }
            else if (n == maxN)
            {
                cnt += currentCnt; // 累加相同大小的棋盘
            }
        }
    }

    cout << maxN << ' ' << cnt << endl;
    return 0;
}