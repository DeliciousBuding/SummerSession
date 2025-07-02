#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string input;
    getline(cin, input);
    int sum = 0;
    for (int i = 0; i < input.length(); i++)
    {
        sum += input[i] - '0';
    }
    //cout << sum << endl;
    string s = to_string(sum);
    //cout << s;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '0':
            cout << "ling";
            break;
        case '1':
            cout << "yi";
            break;
        case '2':
            cout << "er";
            break;
        case '3':
            cout << "san";
            break;
        case '4':
            cout << "si";
            break;
        case '5':
            cout << "wu";
            break;
        case '6':
            cout << "liu";
            break;
        case '7':
            cout << "qi";
            break;
        case '8':
            cout << "ba";
            break;
        case '9':
            cout << "jiu";
            break;
        }
        if (i != s.size() - 1)
            cout << ' ';
    }
}