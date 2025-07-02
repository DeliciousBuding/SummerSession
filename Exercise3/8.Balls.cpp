#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string A, B;
    cin >> A >> B;
    map<char, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        m[A[i]]++;
    }
    bool ok = 1;
    for (int i = 0; i < B.size(); i++)
    {
        m[B[i]]--;
        if (m[B[i]] < 0)
        {
            ok = 0;
        }
    }
    if (ok)
        cout << "Yes " << A.size() - B.size();
    else
    {
        cout << "No ";
        int cnt = 0;
        for (auto it : m)
        {
            if (it.second < 0)
                cnt+=it.second;
        }
        cout << -cnt;
    }
}