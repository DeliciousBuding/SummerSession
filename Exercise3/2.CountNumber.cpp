#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string str;
    cin >> str;
    map<char, int> map;
    for (int i = 0; i < str.length(); i++)
    {
        map[str[i]]++;
    }
    for (auto it : map)
    {
        cout << it.first << ':' << it.second << endl;
    }
}