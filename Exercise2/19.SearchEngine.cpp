#include <bits/stdc++.h>
using namespace std;

string toLower(string &s)
{
    string ans;
    for (char c : s)
    {
        ans += tolower(c);
    }
    return ans;
}

vector<string> split(string &str)
{
    stringstream ss(str);
    string s;
    vector<string> words;
    while (ss >> s)
    {
        words.push_back(toLower(s));
    }
    return words;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        cin.ignore();
        vector<int> recall(n);
        vector<string> titles(n);
        vector<vector<string>> words(n);
        for (int i = 0; i < n; i++)
        {
            getline(cin, titles[i]);
            words[i] = split(titles[i]);
            cin >> recall[i];
            cin.ignore();
        }

        int m;
        cin >> m;
        cin.ignore();
        for (int q = 0; q < m; q++)
        {
            string query;
            getline(cin, query);
            vector<string> qwords = split(query);
            vector<pair<int, int>> matched; //{recall,index}

            for (int i = 0; i < n; i++)
            {
                bool ok = true;
                set<string> st(words[i].begin(), words[i].end());
                for (auto &qw : qwords)
                {
                    if (!st.count(qw))
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    matched.push_back({-recall[i], i});
                }
            }
            sort(matched.begin(), matched.end());
            for (auto &p : matched)
            {
                cout << titles[p.second] << endl;
            }
            if (matched.empty())
                cout << endl;
            cout << "***" << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}
