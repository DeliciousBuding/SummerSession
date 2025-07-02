#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> runner(1000001, vector<int>(2));

int main()
{
    int n, k, minSpeed, maxSpeed, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> runner[i][0];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> runner[i][1];
    }
    minSpeed = maxSpeed = runner[k][1];
    for (int i = 1; i <= n; i++)
    {
        if (runner[i][1] > minSpeed && runner[i][0] < runner[k][0])
        {
            maxSpeed = max(runner[i][1], maxSpeed);
        }
        if (runner[i][1] < maxSpeed && runner[i][0] > runner[k][0])
        {
            minSpeed = min(runner[i][1], minSpeed);
        }
        if (runner[i][0] == runner[k][0])
        { // 起始位置一样，都被感染
            if (runner[i][1] > minSpeed)
            {
                maxSpeed = max(runner[i][1], maxSpeed);
            }
            if (runner[i][1] < maxSpeed)
            {
                minSpeed = min(runner[i][1], minSpeed);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (runner[i][1] > minSpeed && runner[i][0] < runner[k][0])
        {
            maxSpeed = max(runner[i][1], maxSpeed);
        }
        if (runner[i][1] < maxSpeed && runner[i][0] > runner[k][0])
        {
            minSpeed = min(runner[i][1], minSpeed);
        }
        if (runner[i][0] == runner[k][0])
        {
            if (runner[i][1] > minSpeed)
            {
                maxSpeed = max(runner[i][1], maxSpeed);
            }
            if (runner[i][1] < maxSpeed)
            {
                minSpeed = min(runner[i][1], minSpeed);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (runner[i][1] > minSpeed && runner[i][0] < runner[k][0])
        {
            res++;
            maxSpeed = max(runner[i][1], maxSpeed);
        }
        if (runner[i][1] < maxSpeed && runner[i][0] > runner[k][0])
        {
            res++;
            minSpeed = min(runner[i][1], minSpeed);
        }
        if (runner[i][0] == runner[k][0])
        {
            if (runner[i][1] > minSpeed)
                maxSpeed = max(runner[i][1], maxSpeed);
            if (runner[i][1] < maxSpeed)
                minSpeed = min(runner[i][1], minSpeed);
            res++;
        }
    } // 此处我重复循环了3次
    cout << res;
    return 0;
}