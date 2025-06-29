#include <bits/stdc++.h>
using namespace std;

struct Player
{
    string name;
    vector<int> cnt; // 得到第1-10名的次数计数器
    Player() : cnt(100, 0) {}

    int score=0;
};

bool cmp1(Player &player, Player &other)
{
    if (player.score != other.score)
        return player.score > other.score;
    else
    {
        for (int i = 0; i < 100; i++)
        {
            if (player.cnt[i] != other.cnt[i])
            {
                return player.cnt[i] > other.cnt[i];
            }
        }
    }
    return player.name < other.name;
}

bool cmp2(Player &player, Player &other)
{
    if (player.cnt[0] != other.cnt[0])
    {
        return player.cnt[0] > other.cnt[0];
    }
    else
    {
        if (player.score != other.score)
        {
            return player.score > other.score;
        }
        else
        {
            for (int i = 1; i < 100; i++)
            {
                if (player.cnt[i] != other.cnt[i])
                {
                    return player.cnt[i] > other.cnt[i];
                }
            }
        }
    }
    return player.name < other.name;
}
int getScore(int &num)
{
    switch (num)
    {
    case 0:
        return 25;
    case 1:
        return 18;
    case 2:
        return 15;
    case 3:
        return 12;
    case 4:
        return 10;
    case 5:
        return 8;
    case 6:
        return 6;
    case 7:
        return 4;
    case 8:
        return 2;
    case 9:
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    int number = 0;              // 人数
    map<string, Player> players; // key为选手名，Player为选手信息结构体
    for (int i = 0; i < t; i++)
    {
        int n; // 一次比赛的人数
        cin >> n;
        cin.ignore();
        for (int j = 0; j < n; j++)
        {
            string name;
            getline(cin, name);
            if (!players.count(name))
            {
                Player player;
                player.name = name;
                players.insert({name, player});
            }
            players[name].score += getScore(j);
            if (j < 100)
                players[name].cnt[j]++;
        }
    }

    // 拷贝到数组中
    vector<Player> players1, players2;
    for (auto &c : players)
    {
        players1.push_back(c.second);
    }
    players2 = players1;

    // 排序
    sort(players1.begin(), players1.end(), cmp1);
    sort(players2.begin(), players2.end(), cmp2);


    
    cout << players1[0].name << endl
         << players2[0].name << endl;
}