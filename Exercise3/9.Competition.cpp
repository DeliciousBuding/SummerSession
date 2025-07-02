#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a] += b;
    }
    int maxN=0, maxScore=0;
    for (auto it:m)
    {
        if(maxScore<it.second)
        {
            maxScore = it.second;
            maxN = it.first;
        }
    }
    cout << maxN << ' ' << maxScore;
}