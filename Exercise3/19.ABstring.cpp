#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
// 前缀和 统计 区间段的数目
int main()
{
    cin >> s;
    int len = s.length();
    vector<int> cnt(len);//统计[0,i]内的a的个数
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a')
        {
            if (i == 0)
                cnt[i] = 1;
            else
                cnt[i] = cnt[i - 1] + 1;
        }
        else
            cnt[i] = cnt[i - 1];
    }
    //得到前缀和数组cnt

    int min_del = 999999;
    // 时间复杂度为O(len^2)
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            int del = 0;
            // 任何一个部分都有可能是空
            // 最长长度 = 原长度 - 最少删除数
            // 第一部分[0,i) 删除所有'b'

                        if (i != 0)
                del += (i - cnt[i - 1]);
                        // 第二部分[i,j]  删除所有'a'
                        if (i != 0)
                            del += (cnt[j] - cnt[i - 1]);
                        else
                            del += (cnt[j] - cnt[i]);
                        // 第三部分(j,len-1] 删除所有'b'
                        if (j != len - 1)
                            del += ((len - 1 - j) - (cnt[len - 1] - cnt[j]));

                        min_del = min(min_del, del);
        }
    }
    cout << len - min_del << endl;
    return 0;
}