#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x1 = 0, x2 = 0, x3 = 0;       // 甲作为锤子,剪刀,布赢的次数
    int y1 = 0, y2 = 0, y3 = 0;       // 乙作为锤子剪刀布赢的次数
    int win = 0, equal = 0, lose = 0; // 甲赢的次数,平的次数,输的次数
    for (int i = 0; i < n; i++)
    {
        char A, B; // C代表“锤子”、J代表“剪刀”、B代表“布”
        cin >> A >> B;
        if (A == 'C')
        {
            if (B == 'C')
            {
                equal++;
            }
            else if (B == 'J')
            {
                win++;
                x1++;
            }
            else
            {
                lose++;
                y3++;
            }
        }
        else if (A == 'J')
        {
            if (B == 'C')
            {
                lose++;
                y1++;
            }
            else if (B == 'J')
            {
                equal++;
            }
            else
            {
                win++;
                x2++;
            }
        }
        else
        {
            if (B == 'C')
            {
                win++;
                x3++;
            }
            else if (B == 'J')
            {
                lose++;
                y2++;
            }
            else
            {
                equal++;
            }
        }
    }
    cout << win << ' ' << equal << ' ' << lose << endl;
    cout << lose << ' ' << equal << ' ' << win << endl;

    struct Gesture
    {
        char ch;
        int cnt;
        bool operator<(const Gesture &other) const
        {
            if (cnt != other.cnt)
                return cnt > other.cnt; // 胜场多的在前
            return ch < other.ch;       // 胜场一样按字母序
        }
    };

    Gesture aGestures[3] = {{'B', x3}, {'C', x1}, {'J', x2}};
    Gesture bGestures[3] = {{'B', y3}, {'C', y1}, {'J', y2}};

    sort(aGestures, aGestures + 3);
    sort(bGestures, bGestures + 3);

    cout << aGestures[0].ch << ' ' << bGestures[0].ch << endl;
}