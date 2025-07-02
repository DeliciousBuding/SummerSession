#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string A;
    int B;
    cin >> A >> B;
    vector<int> ans(A.size(), 0);
    vector<int> number(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        number[i] = A[i] - '0';
    }
    int temp = 0;
    for (int i = 0; i < A.size(); i++)
    {
        temp += number[i];
        if (temp >= B)
        {
            ans[i] = temp / B;
            temp = (temp % B) * 10;
        }
        else
        {
            ans[i] = 0;
            temp *= 10;
        }
    }
    bool foundNotZero = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (!foundNotZero && ans[i] != 0)
        {
            foundNotZero = 1;
        }
        if (foundNotZero)
        {
            cout << ans[i];
        }
    }

    if (!foundNotZero)
        cout << 0;
    cout << ' ' << temp / 10;
}