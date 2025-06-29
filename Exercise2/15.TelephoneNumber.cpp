#include <bits/stdc++.h>
using namespace std;

bool isSuffix(const string &a, const string &b)
{
    if (a.size() > b.size())
        return false;
    return b.substr(b.size() - a.size()) == a;
}

bool cmp(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length(); // 长度短的在前
    return a < b;                       // 长度相同时按字典序
}

int main()
{
    int n;
    cin >> n;
    map<string, set<string>> all;
    for (int i = 0; i < n; i++)
    {
        string name;
        int num;
        cin >> name >> num;
        for (int j = 0; j < num; j++)
        {
            string number;
            cin >> number;
            all[name].insert(number);
        }
    }

    // 先统计总人数
    cout << all.size() << endl;

    // 处理每个人的号码，去掉是其他号码后缀的号码，按姓名字典序输出
    for (auto &p : all)
    {
        vector<string> arr(p.second.begin(), p.second.end());
        vector<string> filtered;
        for (int i = 0; i < arr.size(); ++i)
        {
            bool is_suffix = false;
            for (int j = 0; j < arr.size(); ++j)
            {
                if (i != j && isSuffix(arr[i], arr[j]))
                {
                    is_suffix = true;
                    break;
                }
            }
            if (!is_suffix)
                filtered.push_back(arr[i]);
        }
        sort(filtered.begin(), filtered.end(), cmp);

        cout << p.first << ' ' << filtered.size();
        for (auto &it : filtered)
        {
            cout << ' ' << it;
        }
        cout << endl;
    }
}