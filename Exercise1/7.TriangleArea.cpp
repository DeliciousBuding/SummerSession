#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
            break; // 输入为0时结束循环
        double area = abs(0.5 * (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2));
        cout << fixed << setprecision(6) << area << endl; // 输出面积，保留6位小数
    }
}