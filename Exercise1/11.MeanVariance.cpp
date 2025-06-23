#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        vector<int> arr(n);
        int sum = 0;
        double sumOfSquares = 0; // 这里的平方和要用double类型，否则会导致整数溢出。
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        double average = double(sum) / n; // 注意这里的sum要转换为double类型，否则会导致整数除法，结果不准确。
        for (int i = 0; i < n; i++)
        {
            double deviation = arr[i] - average;
            sumOfSquares += deviation * deviation;
        }
        double variance = sumOfSquares / n;
        cout << int(variance) << endl;
    }
}