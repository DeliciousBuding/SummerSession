#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    int maxN = 0;
    int minN = INT_MAX;
    int minDiff = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxN = max(maxN, a[i]);
        minN = min(minN, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = abs(abs(a[i] - maxN) - abs(a[i] - minN));
        if (b[i] < minDiff)
        {
            minDiff = b[i];
            minIndex = i;
        }
        else if (b[i] == minDiff && a[i] < a[minIndex])
        {
            minIndex = i; // 如果有相同的最小差值，选择较小的数
        }
    }

    cout << a[minIndex] << endl;
}