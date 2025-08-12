#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string cards;
    cin >> cards;
    map<int, int> m;
    for (int i = 0; i < cards.size(); i++)
    {
        m[cards[i] - '0'] += 1;
    }
    string input;
    while (cin >> input)
    {
        vector<string> ans;
        if (input.size() <= 4)
        {
            int target = input[0] - '0';
            for (int i = target + 1; i <= 9; i++)
            {
                if (m[i]>=input.size())
                {
                    string answer = "";
                    for (int k = 0; k < input.size(); k++)
                        answer += to_string(i);
                    ans.push_back(answer);
                }
            }
        }
        else
        {
            int target = input[0] - '0';
            for (int i = target + 1; i <= 5; i++) // 从i开始往后5个数,看是否存在
            {
                bool ok = 1;
                for (int j = i; j <= i+4; j++)//
                {
                    if (!m[j] > 0)
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    ans.push_back(to_string(i) + to_string(i + 1) + to_string(i + 2) + to_string(i + 3) + to_string(i + 4));
                }
            }
        }
        if (ans.size() > 0)
        {
            cout << "YES ";
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
                if (i != ans.size() - 1)
                    cout << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
