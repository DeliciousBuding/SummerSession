#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // 操作次数
    int m; // 内存大小
    cin >> t >> m;
    int mark = 0;                 // 分配块的唯一标识符，从1递增
    vector<int> memory(m + 1, 0); // 内存空间，1~m，0表示空闲

    for (int i = 0; i < t; i++)
    {
        string command;
        cin >> command;

        if (command == "alloc")
        {
            int parameter;
            cin >> parameter;
            bool allocated = false;
            int j = 1;
            while (j <= m - parameter + 1)
            {
                // 检查区间[j, j+parameter-1]
                bool can_alloc = true;
                for (int k = j; k < j + parameter; k++)
                {
                    if (memory[k] != 0)
                    {
                        // 跳到下一个非空闲区间的末尾+1
                        j = k + 1;
                        can_alloc = false;
                        break;
                    }
                }
                if (can_alloc)
                {
                    mark++;
                    for (int k = j; k < j + parameter; k++)
                        memory[k] = mark;
                    cout << mark << endl;
                    allocated = true;
                    break;
                }
            }
            if (!allocated)
                cout << "NULL" << endl;
        }
        else if (command == "erase")
        {
            int parameter;
            cin >> parameter;
            bool found = false; // 是否找到要删除的块
            for (int j = 1; j <= m; j++)
            {
                if (memory[j] == parameter)
                {
                    memory[j] = 0; // 释放该块
                    found = true;
                }
            }
            if (!found)
            {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl; // 没有找到该编号
            }
        }
        else if (command == "defragment")
        {
            // 整理内存碎片，把所有已分配块往前移动，顺序不变
            vector<int> new_memory(m + 1, 0); // 新内存空间
            int index = 1;                    // 新内存的当前位置
            for (int j = 1; j <= m; j++)
            {
                if (memory[j] != 0)
                {
                    new_memory[index++] = memory[j]; // 复制到新内存
                }
            }
            memory = new_memory; // 更新内存
        }
    }
}