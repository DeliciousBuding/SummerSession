#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        //按空格分割
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word)
        {
            words.push_back(word);
        }
        for (int i = words.size() - 1; i >= 0; i--)
        {
            cout << words[i];
            if(i>0)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}