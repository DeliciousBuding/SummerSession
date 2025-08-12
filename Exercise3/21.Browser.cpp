#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    string input;
    stack<string> A, B;
    string now = "http://www.game.org/";
    while (getline(cin, input) && input != "QUIT")
    {
        //cout << "test" << endl;
        if (input == "BACK")
        {
            if(B.empty())
            {
                cout<<"Ignored"<<endl;
                continue;
            }
            A.push(now);
            now = B.top();
            B.pop();
        }
        else if (input == "FORWARD")
        {
           if(A.empty())
            {
                cout<<"Ignored"<<endl;
                continue;
            }
            B.push(now);
            now = A.top();
            A.pop();
        }
        else
        {
            // VISIT
            istringstream ss(input);
            string a, command;
            ss >> a >> command;
            B.push(now);
            while (!A.empty())
                A.pop();
            now = command;
        }
        cout << now << endl;
    }

    return 0;
}
