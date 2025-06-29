#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &word, const string &dict)
{
    // 1. 从单词中删除一个字母
    for (int i = 0; i < word.size(); i++)
    {
        string deleteWord = word.substr(0, i) + word.substr(i + 1);
        if (deleteWord == dict)
        {
            return true;
        }
    }

    // 2. 用一个任意字母替换单词中的一个字母
    if (word.size() == dict.size())
    {
        int diff = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] != dict[i])
                diff++;
        }
        if (diff == 1)
            return true;
    }

    // 3. 在单词中插入一个任意字母
    if (word.size() + 1 == dict.size())
    {
        for (int i = 0; i < word.size(); i++) // 注意这里是<=，允许末尾插入
        {
            for (int j = 0; j < 26;j++)
            {
                string alaphabet(1,'a'+j);
                string str = word;
                str.insert(i, alaphabet);
                if(str==dict)
                {
                    return 1;
                }
            }
        }
        for (int j = 0; j < 26; j++)
        {
            string alaphabet(1, 'a' + j);
            string str = word+alaphabet;
            if (str == dict)
            {
                return 1;
            }
        }
    }

    return false;
}

void Process(const string &word, const vector<string> &dict)
{
    // 遍历dict中的每个单词与word进行比较
    vector<string> replace;

    for (const string &str : dict)
    {
        if (str == word)
        {
            cout << word << " is correct" << endl;
            return;
        }
        else if (isValid(word, str))
        {
            replace.push_back(str);
        }
    }

    cout << word << ":";
    if (!replace.empty())
    {
        cout << " ";
        for (int i = 0; i < replace.size(); i++)
        {
            cout << replace[i];
            if (i != replace.size() - 1)
                cout << ' ';
        }
    }
    cout << endl;
}

int main()
{
    vector<string> dict;
    string word;

    // 读取字典
    while (cin >> word && word != "#")
    {
        dict.push_back(word);
    }

    // 处理待检查的单词
    while (cin >> word && word != "#")
    {
        Process(word, dict);
    }

    return 0;
}