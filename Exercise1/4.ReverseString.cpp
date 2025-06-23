#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s); // 读取整行字符串
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') // 如果遇到空格或是字符串的最后一个字符
            {
                reverse(temp.begin(), temp.end()); // 反转临时字符串
                cout << temp;   // 输出反转后的字符串
                temp.clear(); // 清空临时字符串
                cout << " ";  // 输出空格
                continue;     // 跳过空格
            }
            if(s[i] == s[s.size() - 1]) // 如果是字符串的最后一个字符
            {
                temp.push_back(s[i]); // 将最后一个字符添加到临时字符串
                reverse(temp.begin(), temp.end()); // 反转临时字符串
                cout << temp; // 输出反转后的字符串
                temp.clear(); // 清空临时字符串
                continue; // 跳过最后一个字符
            }
            temp.push_back(s[i]); // 将非空格字符添加到临时字符串
        }
        cout << endl;
    }
}