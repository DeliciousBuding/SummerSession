#include <bits/stdc++.h>
using namespace std;
vector<int> intToBinary(int num)
{
    vector<int> binary;
    if (num == 0)
    {
        binary.push_back(0);
        return binary;
    }
    while (num > 0)
    {
        binary.push_back(num % 2);
        num /= 2;
    }
    return binary;
}
int calculateTheNumberofOneInBinary(vector<int> &num)
{
    int count = 0;
    for (int i = 0; i < 4;i++)
    {
        vector<int> binary = intToBinary(num[i]); // 将每个部分转换为二进制
        for (int j = 0; j < binary.size(); j++)
        {
            if (binary[j] == 1) // 统计二进制中1的个数
            {
                count++;
            }
        }
    }
    return count;
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> IP(4);                                            // 用于存储IP地址的四个部分
        char dot;                                                     // 用于读取点分隔符
        cin >> IP[0] >> dot >> IP[1] >> dot >> IP[2] >> dot >> IP[3]; // 输入IP地址的四个部分
        int count = calculateTheNumberofOneInBinary(IP);
        cout << count << endl;
    }
}