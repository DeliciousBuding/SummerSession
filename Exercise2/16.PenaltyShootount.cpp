#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    while (cin >> N && N != 0)
    {
        cin.ignore(); // 忽略换行符

        vector<int> teamA, teamB; // 存储两队的点球结果

        for (int i = 0; i < N; i++)
        {
            string line;
            getline(cin, line);

            bool scored = false;
            // 先检查 "no good"，再检查 "good"
            if (line.find(" no good") != string::npos)
                scored = false;
            else if (line.find(" good") != string::npos)
                scored = true;

            // 奇数次（0,2,4...）是A队，偶数次（1,3,5...）是B队
            if (i % 2 == 0)
                teamA.push_back(scored ? 1 : 0);
            else
                teamB.push_back(scored ? 1 : 0);
        }

        // 计算轮数
        int rounds = (N + 1) / 2;

        // 输出表头
        for (int i = 1; i <= rounds; i++)
        {
            cout << i << " ";
        }
        cout << "Score" << endl;

        // 输出A队结果
        int scoreA = 0;
        for (int i = 0; i < rounds; i++)
        {
            if (i < teamA.size())
            {
                if (teamA[i] == 1)
                {
                    cout << "O ";
                    scoreA++;
                }
                else
                {
                    cout << "X ";
                }
            }
            else
            {
                cout << "- ";
            }
        }
        cout << scoreA << endl;

        // 输出B队结果
        int scoreB = 0;
        for (int i = 0; i < rounds; i++)
        {
            if (i < teamB.size())
            {
                if (teamB[i] == 1)
                {
                    cout << "O ";
                    scoreB++;
                }
                else
                {
                    cout << "X ";
                }
            }
            else
            {
                cout << "- ";
            }
        }
        cout << scoreB << endl;
    }

    return 0;
}