#include <bits/stdc++.h>
using namespace std;

/**
 * 递归函数：计算符合模式s并且比数字n大的数量
 * @param s 带通配符'?'的字符串模式
 * @param n 用于比较的目标数字字符串
 * @param cnt 剩余未处理的'?'的数量
 * @return 满足条件的数字个数
 */
long long check(string s, string n, long long cnt)
{
    // 递归终止条件：没有'?'需要处理了
    if (cnt == 0)
    {
        // 直接比较字符串s和n的大小关系
        return (s > n) ? 1 : 0;
        // 当所有 '?' 都被替换完毕后，检查最终构造出的数字是否大于目标数字 X。
        //所有的判断条件的微元都是从这里出发
    }

    long long flag = 0; // 标记当前s和n的比较状态
    long long ans = 1;  // 存储答案

    // 从左到右扫描字符串，寻找第一个'?'
    for (int i = 0; i < s.size(); ++i)
    {

        // 找到第一个'?'，开始处理
        if (s[i] == '?')
        {
            if (flag == 0)
            {
                // 情况1：前面所有位都相等，当前位是关键位
                s[i] = n[i]; // 先让'?'等于n[i]
                // 计算总方案数：
                // ('9' - n[i]) * pow(10, cnt-1)：当前位填比n[i]大的数字的方案数
                // check(s, n, cnt-1)：当前位填n[i]时，后续位的方案数
                ans *= ('9' - n[i]) * pow(10, cnt - 1) + check(s, n, cnt - 1);
            }
            else if (flag == 1)
            {
                // 情况2：前面已经比n大了，后面随便填
                ans = pow(10, cnt); // 剩余cnt个'?'，每个有10种选择
            }
            else
            {
                // 情况3：前面已经比n小了，无法超过n
                ans = 0;
            }
            break; // 处理完第一个'?'就退出循环
        }

        // 更新flag状态，记录当前s和n的比较关系
        if (s[i] == n[i])
        {
            flag = 0; // 相等，继续比较
        }
        else if (flag != 2 && s[i] > n[i])
        {
            flag = 1; // s比n大
        }
        else if (flag != 1)
        {
            flag = 2; // s比n小
        }
    }

    return ans;
}

/**
 * 主要求解函数
 */
void solve()
{
    string s, n;
    while (cin >> s >> n)
    {
        // 统计模式字符串s中'?'的个数
        long long cnt = 0;
        for (const auto &item : s)
        {
            if (item == '?')
                ++cnt;
        }

        // 调用递归函数并输出结果
        cout << check(s, n, cnt) << endl;
    }
}

int main()
{
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve(); // 调用求解函数
    return 0;
}