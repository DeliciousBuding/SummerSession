#include <bits/stdc++.h>
using namespace std;

// 0~9的7段数码管编码（a-g，按顺序，1为亮，0为灭）
const int seg[10] = {
    0b1111110, // 0
    0b0110000, // 1
    0b1101101, // 2
    0b1111001, // 3
    0b0110011, // 4
    0b1011011, // 5
    0b1011111, // 6
    0b1110000, // 7
    0b1111111, // 8
    0b1111011  // 9
};

int main()
{
    ios::sync_with_stdio(0);
    while (true)
    {
        vector<int> arr(10);
        for (int i = 0; i < 10; i++)
        {
            cin >> arr[i];
            if (i == 0 && arr[i] == -1)
                return 0;
        }
        bool ok = true;
        for (int i = 0; i < 9; i++)
        {
            int from = seg[arr[i]];
            int to = seg[arr[i + 1]];
            int add = (to & ~from); // 需要加的笔
            int sub = (from & ~to); // 需要减的笔
            if (add && sub)         // 既有加又有减
            {
                ok = false;
                break;
            }

            
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}