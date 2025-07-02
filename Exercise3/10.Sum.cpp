#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    std::ios::sync_with_stdio(0);
    int a, b; // 次数 系数
    map<int, int> m;
    while (cin >> a >> b)
    {
        m[a] += b;
    }

    vector<pair<int, int>> v;

    for (auto it : m)
    {
        v.push_back({it.first, it.second});
    }

    sort(v.begin(), v.end(), cmp);
    for (auto it : v)
    {
        if(it.second==0)
            continue;
        cout << it.first << ' ' << it.second << endl;
    }
}