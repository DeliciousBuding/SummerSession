#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    map<string, string> m1, m2;
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "@END@")
        {
            break;
        }

        string name = input.substr(0, input.find(']') + 1);
        string function = input.substr(input.find(' ') + 1);
        // cout << name << ' ' << function << endl;
        m1[name] = function;
        m2[function] = name;
    }
    int n;
    cin >> n;
    cin.ignore();
    // cout << "!";
    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin, input);
        if (m1.count(input))
            cout << m1[input] << endl;
        else if (m2.count(input))
        {
            for (auto it : m2[input])
                if (it != '[' && it != ']')
                    cout << it;
            cout << endl;
        }
        else
            cout << "what?" << endl;
    }
    return 0;
}
