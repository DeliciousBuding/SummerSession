// 根据读入符号处理，若为+则入栈，若为*则继续操作，最后在统合
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
