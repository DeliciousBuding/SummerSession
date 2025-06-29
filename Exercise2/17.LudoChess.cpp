#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B, C;
    while (cin >> N >> A >> B >> C)
    {
        vector<int> board(N);

        // 读取棋盘信息
        for (int i = 0; i < N; i++)
        {
            string input;
            cin >> input;

            if (input == "N")
                board[i] = -1; // -1表示普通格子
            else
                board[i] = stoi(input.substr(1)); // 特殊格子，飞到指定位置
        }

        // 游戏状态
        int lele_pos = 0, yueyue_pos = 0; // 两个玩家的位置
        int dice = (A * C + B) % 6 + 1;   // 第一个骰子点数
        bool lele_turn = true;            // true表示Lele的回合

        // 游戏循环
        while (true)
        {
            int current_pos, new_pos;

            if (lele_turn)
            {
                current_pos = lele_pos;
            }
            else
            {
                current_pos = yueyue_pos;
            }

            // 计算新位置
            new_pos = current_pos + dice;

            // 处理超出边界的情况（往回走）
            if (new_pos >= N)
            {
                new_pos = 2 * (N - 1) - new_pos;
                if (new_pos < 0)
                    new_pos = 0;
            }

            // 处理特殊格子（连续飞行）
            while (board[new_pos] != -1)
            {
                new_pos = board[new_pos];
            }

            // 检查是否到达终点
            if (new_pos == N - 1)
            {
                if (lele_turn)
                    cout << "Lele" << endl;
                else
                    cout << "Yueyue" << endl;
                break;
            }

            // 处理踢人规则（除了第0格）
            if (new_pos != 0)
            {
                if (lele_turn)
                {
                    if (yueyue_pos == new_pos)
                        yueyue_pos = 0; // 踢回起点
                    lele_pos = new_pos;
                }
                else
                {
                    if (lele_pos == new_pos)
                        lele_pos = 0; // 踢回起点
                    yueyue_pos = new_pos;
                }
            }
            else
            {
                // 如果是第0格，直接更新位置
                if (lele_turn)
                    lele_pos = new_pos;
                else
                    yueyue_pos = new_pos;
            }

            // 切换玩家
            lele_turn = !lele_turn;

            // 计算下一个骰子点数
            dice = (A * dice + B) % 6 + 1;
        }
    }
    return 0;
}