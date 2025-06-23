#include <bits/stdc++.h>
using namespace std;



int calculateDegree(const string &s)
{
    int degree = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            if(s[i] > s[j])
            {
                degree++;
            }
        }
    }
    return degree;
}
bool cmp(const string &a, const string &b)
{
    if(calculateDegree(a) != calculateDegree(b))
    {
        return calculateDegree(a) < calculateDegree(b);
    }
    else
    {
        return a < b; // 如果度数相同，则按字典序排序
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<string> strings(m);
    for (int i = 0; i < m; i++)
    {
        getline(cin, strings[i]);
    }
    sort(strings.begin(), strings.end(),cmp);
    for (int i = 0; i < m; i++)
    {
        cout << strings[i];
        if (i != m - 1)
        {
            cout << endl; // 输出换行符
        }
    }
}