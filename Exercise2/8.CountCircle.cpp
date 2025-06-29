#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int x = n / 2, y = n / 2; // 中心点
    if (n % 2 == 0)
    { // 偶数中心在左上
        x = n / 2 - 1;
        y = n / 2 - 1;
    }
    // 自己手搓一遍
    a[x][y] = 1;
    int num = 2;
    int dx[] = {0, 1, 0, -1}; // 右 下 左 上
    int dy[] = {1, 0, -1, 0};

    int step = 1, dir = 0;//dir为0,1,2,3时对应dx和dy数组即x,y移动的方向

    while(num<=n*n)
    {
        for (int i = 0; i < 2;i++)
        {
            for (int j = 0; j < step;j++)
            {
                x += dx[dir];
                y += dy[dir];

                if (x >= 0 && x < n && y >= 0 && y < n)
                    a[x][y] = num++;
            }
            dir = (dir + 1) % 4;
        }
        //每移动两次步长+1
        step++;
    }

    // 输出
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << a[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}