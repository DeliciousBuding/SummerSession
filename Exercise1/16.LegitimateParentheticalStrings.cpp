#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;
        stack<char> stack;
        bool isValid = true;
        for(char c:input)
        {
            if(c=='('||c=='<'||c=='{'||c=='[')
            {
                stack.push(c);
            }
            else if(c==')')
            {
                if(!stack.empty()&&stack.top()=='(')
                {
                    stack.pop();
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if(c=='>')
            {
                if(!stack.empty()&&stack.top()=='<')
                {
                    stack.pop();
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if(c=='}')
            {
                if(!stack.empty()&&stack.top()=='{')
                {
                    stack.pop();
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if(c==']')
            {
                if(!stack.empty()&&stack.top()=='[')
                {
                    stack.pop();
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
        }
        if(isValid && stack.empty())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}