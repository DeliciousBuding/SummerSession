#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int n; // 座位排数
    int m; // 人数
    int k; // 命令数

    cin >> n >> m >> k;
    cin.ignore();

    // 座位状态：-1表示空闲，其他数字表示被对应id占用
    vector<int> seats(n * n, -1);

    // 记录每个用户占用的座位区间 [start, end]

    // 区间用pair来存储
    vector<pair<int, int>> userSeats(m, {-1, -1});

    // 处理命令
    for (int i = 0; i < k; i++)
    {
        string input;
        getline(cin, input);
        istringstream ss(input);

        string command;
        ss >> command;

        if (command == "in")
        {
            int id, num;
            ss >> id >> num;

            // 检查用户是否已经占座
            if (userSeats[id].first != -1)
            {
                cout << "no" << endl; // 如果id之前占过座还没释放那么之后他的in命令都是无效的
                continue;
            }

            // 寻找连续的num个空座位（最先适配法）
            bool found = false;
            int start = -1;

            for (int j = 0; j <= n * n - num; j++)
            {
                bool canAllocate = true;

                // 检查从位置j开始的num个座位是否都空闲
                for (int k = j; k < j + num; k++)
                {
                    if (seats[k] != -1)
                    {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate)
                {
                    start = j;
                    found = true;
                    break;
                }
            }

            if (found)
            {
                // 分配座位
                for (int j = start; j < start + num; j++)
                {
                    seats[j] = id;
                }
                userSeats[id] = {start, start + num - 1};
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }

        else if (command == "out")
        {
            int id;
            ss >> id;

            // 检查用户是否有占座
            if (userSeats[id].first == -1)
            {
                cout << "no" << endl;
                continue;
            }

            // 释放座位
            int start = userSeats[id].first;
            int end = userSeats[id].second;

            for (int j = start; j <= end; j++)
            {
                seats[j] = -1;
            }

            userSeats[id] = {-1, -1};
            cout << "yes" << endl;
        }
    }

    return 0;
}
