// 1.Equation
#include <bits/stdc++.h>

using namespace std;

struct e
{
    int A;
    int B;
    int C;
};

void cal(e x, e y)
{
    int rx = 0, ry = 0;
    rx = (-x.C * y.B + x.B * y.C) / (x.A * y.B - x.B * y.A);
    ry = (-x.A * y.C + x.C * y.A) / (x.A * y.B - x.B * y.A);
    cout << rx << " " << ry << " ";
}

int main()
{
    int N = 0;

    cin >> N;
    e *all = new e[N];
    // 接下来 N 行，每行包含A、B、C三个整数，表示一个形如“Ax+By+C=0”形式的二元一次方程。
    for (int i = 0; i < N; i++)
        cin >> all[i].A >> all[i].B >> all[i].C;
    for (int i = 0; i < N - 1; i++) // 两两组合求解
    {
        for (int j = i + 1; j < N; j++)
            cal(all[i], all[j]);
        cout << endl;
    }
    return 0;
}

// 2.Museum
#include <bits/stdc++.h>
using namespace std;
const int N = 100000007;
long long dp[1000010];

int main()
{
    std::ios::sync_with_stdio(0);
    int n, a, b;
    long long s;
    cin >> n >> s >> a >> b;
    int maxSum = n * (n - 1) / 2;

    dp[0] = 1;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = (i + 1) * i / 2; j >= i; --j)
        {
            dp[j] += dp[j - i];
            dp[j] %= N;
        }
    }

    long long low = -maxSum * (long long)a + s;

    int cnt = 0;
    long long f = low % n;
    long long q = (a + b) % n;

    for (int i = 0; i <= maxSum; i++)
    {
        if (((long long)i * q + f) % (long long)n == 0)
        {
            cnt += dp[i];
            cnt = cnt % N;
        }
    }
    cout << cnt;
    return 0;
}

// 3
//  根据读入符号处理，若为+则入栈，若为*则继续操作，最后在统合
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    long long num1, num2, ans = 0;
    char ch;
    cin >> num1;
    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case '+':

            st.push(num1);
            cin >> num1;
            break;
        case '*':
            cin >> num2;
            num1 = num1 * num2;
            break;
        }
        if (num1 > 10000)
            num1 %= 10000;
    }
    st.push(num1);
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        if (ans > 10000)
            ans %= 10000;
    }
    cout << ans << endl;
    return 0;
}
