#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string max_name, max_id, min_name, min_id;
    int max_score = -1, min_score = 101;
    for (int i = 0; i < n; ++i)
    {
        string name, id;
        int score;
        cin >> name >> id >> score;
        if (score > max_score)
        {
            max_score = score;
            max_name = name;
            max_id = id;
        }
        if (score < min_score)
        {
            min_score = score;
            min_name = name;
            min_id = id;
        }
    }
    cout << max_name << " " << max_id << endl;
    cout << min_name << " " << min_id << endl;
    return 0;
}