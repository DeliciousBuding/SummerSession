#include <bits/stdc++.h>
using namespace std;

int ans(const vector<vector<int>> &arr)
{
    // 行
    for (int x = 0; x < 3; x++)
        if (arr[x][0] == arr[x][1] && arr[x][0] == arr[x][2] && arr[x][0] != 0)
            return arr[x][0];
    // 列
    for (int x = 0; x < 3; x++)
        if (arr[0][x] == arr[1][x] && arr[0][x] == arr[2][x] && arr[0][x] != 0)
            return arr[0][x];
    // 对角线
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != 0)
        return arr[0][0];
    if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[1][1] != 0)
        return arr[1][1];
    return 0; // 理论上不会到这里
}

int main()
{
    int n;
    string player;
    cin >> n;
    cin.ignore();
    getline(cin, player);
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> arr(3, vector<int>(3));
        for (int x = 0; x < 3; x++)
        {
            string A;
            getline(cin, A);
            for (int y = 0; y < 3; y++)
                arr[x][y] = A[y] - '0'; // 字符转数字
        }
        int winner = ans(arr);
        // 先手是player[i]，先手执1，后手执2
        if (winner == 1)
            cout << player[i] << endl;
        else
            cout << (player[i] == 'A' ? 'B' : 'A') << endl;
    }
}