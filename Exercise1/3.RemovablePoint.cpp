#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < 0)
            left++;
        else
            right++;

        if (left > 1 && right > 1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (left <= 1 || right <= 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}