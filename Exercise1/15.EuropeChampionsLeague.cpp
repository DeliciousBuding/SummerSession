#include <bits/stdc++.h>
using namespace std;

// 球队结构体
struct Team
{
    string name;
    int score = 0;          // 积分
    int goalDifference = 0; // 净胜球

    // 用于排序：先按积分降序，再按净胜球降序，最后按名字升序
    bool operator<(const Team &other) const
    {
        if (score != other.score)
            return score > other.score;
        if (goalDifference != other.goalDifference)
            return goalDifference > other.goalDifference;
        return name < other.name;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        // 用map保证每个球队唯一，方便累计积分和净胜球
        map<string, Team> teamMap;
        for (int i = 0; i < 12; i++)
        {
            string homeTeam, vs, awayTeam;
            int homeScore, awayScore;
            cin >> homeTeam >> homeScore >> vs >> awayScore >> awayTeam;

            // 初始化球队信息
            if (!teamMap.count(homeTeam))
                teamMap[homeTeam] = Team{homeTeam, 0, 0};
            if (!teamMap.count(awayTeam))
                teamMap[awayTeam] = Team{awayTeam, 0, 0};

            // 更新净胜球
            teamMap[homeTeam].goalDifference += homeScore - awayScore;
            teamMap[awayTeam].goalDifference += awayScore - homeScore;

            // 更新积分
            if (homeScore > awayScore)
            {
                teamMap[homeTeam].score += 3;
            }
            else if (homeScore == awayScore)
            {
                teamMap[homeTeam].score += 1;
                teamMap[awayTeam].score += 1;
            }
            else
            {
                teamMap[awayTeam].score += 3;
            }
        }

        // 将map中的球队转为vector，方便排序
        vector<Team> teams;
        for (auto &p : teamMap)
            teams.push_back(p.second);

        // 排序，使用结构体中的operator<
        sort(teams.begin(), teams.end());

        // 输出前四名
        for (int i = 0; i < 2 && i < teams.size(); i++)
        {
            cout << teams[i].name << ' ';
        }
        cout << endl;
    }
}