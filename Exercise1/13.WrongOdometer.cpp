#include <iostream>
#include <string>
using namespace std;

// 里程表显示数字到8进制数字的映射
int mapDigit(char c)
{
    if (c == '0')
        return 0;
    if (c == '1')
        return 1;
    if (c == '2')
        return 2;
    if (c == '4')
        return 3;
    if (c == '5')
        return 4;
    if (c == '6')
        return 5;
    if (c == '7')
        return 6;
    if (c == '9')
        return 7;
    return -1; // 不会出现
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        long long ans = 0;
        for (char c : s)
        {
            ans = ans * 8 + mapDigit(c);
        } 
        cout << ans << endl;
    }
}