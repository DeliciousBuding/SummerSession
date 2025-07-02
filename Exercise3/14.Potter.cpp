#include <bits/stdc++.h>
using namespace std;

// 错误原因:name里面可能有空格..
int main()
{
    std::ios::sync_with_stdio(0);
    map<string, string> m1;
    map<string, vector<string>> m2;
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "@END@")
        {
            break;
        }

        size_t pos = input.find(']');
        string name = input.substr(0, pos + 1);  // 取到']'
        string function = input.substr(pos + 2); // 跳过'] '
        m1[name] = function;
        m2[function].push_back(name);
    }
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin, input);
        if (m1.count(input)) // 输入是魔咒名
            cout << m1[input] << endl;
        else if (m2.count(input)) // 输入是功能
        {
            // 输出第一个魔咒名，去掉方括号
            string name = m2[input][0];
            cout << name.substr(1, name.size() - 2) << endl;
        }
        else
            cout << "what?" << endl;
    }
    return 0;
}
