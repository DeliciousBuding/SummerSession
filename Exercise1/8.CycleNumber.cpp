#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 检查 t 是否是 s 的循环（环形）变换
bool isCyclic(const string &s, const string &t)
{
    return s.size() == t.size() && (s + s).find(t) != string::npos;//把s拼接成s+s，然后检查t是否是s+s的子串，这样方便检查循环的字符串！
}

// 字符串大数乘法
string multiply(const string &num, int k) // 2<= k <= 60
{
    int n = num.size();
    vector<int> result(n + 10, 0); // 多留空间防止进位溢出
    // 从最低位开始逐位相乘
    for (int i = n - 1; i >= 0; i--)
    {
        int mul = (num[i] - '0') * k;
        result[i + result.size() - n] += mul; // 将num的最低位对齐到result的最低位
    }
    // 处理进位
    for (int i = result.size() - 1; i > 0; --i)
    {
        if (result[i] >= 10)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    // 转成字符串，去除前导零但保留原始长度
    string res;
    int start = 0;
    while (start < result.size() - 1 && result[start] == 0)
        start++; // 找到第一个非零位
    for (int i = start; i < result.size(); ++i)
        res += result[i] + '0'; // 将数字转换为字符
    // 保持前导零
    while (res.size() < num.size())
        res = "0" + res; // 补前面的0
    return res;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    bool flag = true;
    for (int i = 2; i <= n; ++i)
    {
        string t = multiply(s, i);
        // 保持长度一致（前导零）
        if (t.size() > n)
        {
            flag = false;
            break;
        }
        if (!isCyclic(s, t))
        {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}