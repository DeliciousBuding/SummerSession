#include <bits/stdc++.h>
using namespace std;
vector<int> score, goalDifference, goalScored;
vector<string> name;
bool cmp(int a, int b)
{
    if (score[a] != score[b])
        return score[a] > score[b];
    if (goalDifference[a] != goalDifference[b])
        return goalDifference[a] > goalDifference[b];
    if (goalScored[a] != goalScored[b])
        return goalScored[a] > goalScored[b];
    return name[a] < name[b];
}

int main()
{
    int n; // 球队数量
    cin >> n;
    name.resize(n);
    score.assign(n, 0);
    goalDifference.assign(n, 0);
    goalScored.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    cin.ignore();
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        string input;
        getline(cin, input); // A-B 1:1
        string homeName, awayName;
        int homeScore, awayScore;

        // 分割字符串
        string A, B;
        bool foundSpace = 0;
        for (char c : input)
        {
            if (c != ' ' && !foundSpace)
                A = A + c;
            if (c == ' ')
                foundSpace = 1;
            if (c != ' ' && foundSpace)
                B = B + c;
        }
        string a1, b1;
        bool found1 = 0;
        for (char c : A)
        {
            if (c != '-' && !found1)
            {
                a1 = a1 + c;
            }
            if (c == '-')
                found1 = 1;
            if (c != '-' && found1)
            {
                b1 = b1 + c;
            }
        }
        homeName = a1;
        awayName = b1;
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (homeName == name[i])
                index1 = i;
            if (awayName == name[i])
                index2 = i;
            if (index1 > -1 && index2 > -1)
                break;
        }
        string a2, b2;
        bool found2 = 0;
        for (char c : B)
        {
            if (c != ':' && !found2)
            {
                a2 = a2 + c;
            }
            if (c == ':')
                found2 = 1;
            if (c != ':' && found2)
            {
                b2 = b2 + c;
            }
        }
        homeScore = stoi(a2);
        awayScore = stoi(b2);

        if (homeScore > awayScore)
        {
            score[index1] += 3;
        }
        else if (homeScore == awayScore)
        {
            score[index1] += 1;
            score[index2] += 1;
        }
        else
        {
            score[index2] += 3;
        }

        goalDifference[index1] += homeScore - awayScore;
        goalDifference[index2] += awayScore - homeScore;

        goalScored[index1] += homeScore;
        goalScored[index2] += awayScore;
    }
    // 然后进行排序 按照得分 净进球数 进球数排名
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;
    sort(idx.begin(), idx.end(), cmp);

    // 取前 n/2 名，按字典序输出
    vector<string> qualified;
    for (int i = 0; i < n / 2; i++)
    {
        qualified.push_back(name[idx[i]]);
    }
    sort(qualified.begin(), qualified.end());
    for (const string &team : qualified)
    {
        cout << team << endl;
    }
}