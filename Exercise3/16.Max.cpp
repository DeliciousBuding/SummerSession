#include <bits/stdc++.h>
using namespace std;

bool cmp(double A, double B)
{
    return A > B;
}

int main()
{
    std::ios::sync_with_stdio(0);
    while (1)
    {
        double Q;
        int N;
        cin >> Q >> N;
        if (N == 0)
            return 0;
        double Max = 0;
        vector<double> v;
        for (int i = 0; i < N; i++)
        {
            int m;
            cin >> m;
            bool ok = 1;
            double sum = 0;
            vector<string> input;
            for (int j = 0; j < m; j++)
            {
                string str;
                cin >> str;
                int point = str.find(':');
                char kind = str[0];
                if(!(kind=='A'||kind=='B'||kind=='C'))
                {
                    
                    //cout << kind<<'!'<<endl;
                    ok = 0;
                    break;
                }
                double price = stod(str.substr(2));
                sum += price;
                if (price > 600 || sum > 1000) // 单张发票是否可行
                {
                    ok = 0;
                    break;
                }
                // cout << price << ' ';
            }

            if (ok)
            {
                v.push_back(sum);
            }
        }

        sort(v.begin(), v.end(), cmp); // 降序排序
        double sum = 0;
        for (auto it : v)
        {
            if (sum + it <= Q)
            {
                sum += it;
            }
        }
        cout << fixed << setprecision(2) << sum << endl;
    }

    return 0;
}
