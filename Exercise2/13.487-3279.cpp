#include <bits/stdc++.h>
using namespace std;
int mapping(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
        return 9;
    default:
        return -1; // 其他字符（如Q、Z、数字、-）返回-1
    }
}

string transfer(string &A)
{
    string ans;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '-')
            continue;
        if ('0' <= A[i] && A[i] <= '9')
        {
            ans += A[i];
        }
        if ('A' <= A[i] && A[i] <= 'Z')
        {
            ans += char(mapping(A[i]) + '0');
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    map<string, int> map;
    while (n--)
    {
        string input;
        getline(cin, input);
        string name = transfer(input);
        if (map.count(name))
        {
            map[name]++;
        }
        else
        {
            map[name] = 1;
        }
    }
    for (auto n : map)
    {
        if (n.second > 1)
        {
            for (int i = 0; i < 3; i++)
                cout << n.first[i];
            cout << '-';
            for (int i = 3; i < n.first.size(); i++)
                cout << n.first[i];
            cout << ' ' << n.second << endl;
        }
    }
}