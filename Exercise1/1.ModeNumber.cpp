#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {

        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        vector<int> v(10001,0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[x]++;
        }
        int mode = 0;
        for (int i = 1; i < 10001; i++)
        {
            if (v[i] > v[mode])
            {
                mode = i;
            }
        }
        cout << mode << endl;
    }
}