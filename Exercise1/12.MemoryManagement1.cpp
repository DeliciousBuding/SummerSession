#include <bits/stdc++.h>
using namespace std;

// 错误版本 用于对比学习
int main()
{
    int t; // 命令条数
    int m; // 内存大小
    cin >> t >> m;
    int mark = 0;                 // 标记 表示内存块的序号
    vector<int> memory(m + 1, 0); // 索引从1开始的内存，初始化为0，空
    for (int i = 0; i < t; i++)   // 读取并进行每一步
    {
        string command; // 命令
        cin >> command;
        int parameter; // 参数
        cin >> command >> parameter;
        if (command == "alloc") // 分配内存
        {
            bool allocated = false;      // 标记是否分配成功
            for (int j = 1; j <= m; j++) // 查找空闲的连续的内存
            {
                for (int k = j; k <= parameter + j - 1; k++)
                {
                    if (memory[k] != 0)
                    {
                        break; // 如果有一个内存不为空，则跳出
                    }
                    if (k == parameter + j) // 如果连续的内存都为空
                    {
                        mark++;                                  // 增加标记
                        for (int l = j; l <= parameter + j; l++) // 分配内存
                        {

                            memory[l] = mark; // 分配给第i个命令
                        }
                        cout << mark << endl; // 输出分配的内存块序号
                        allocated = true;     // 标记为已分配
                        // cout << "Allocated " << parameter << " bytes at " << j << endl;
                        break; // 跳出内层循环
                    }
                }
            }
            if (!allocated)
            {
                cout << "NULL" << endl;
            }
        }
        else if (command == "erase")
        {
            bool found = false;          // 标记是否找到要删除的内存块
            for (int j = 1; j <= m; j++) // 全部遍历一遍，发现要删的内存块就删掉（比较暴力）
            {
                if (memory[j] == parameter) // 如果内存块的序号等于参数
                {
                    memory[j] = 0; // 清除内存
                    found = true;  // 标记为已找到
                }
            }
            if (!found)
            {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        }
        else if (command == "defragment") // 把内存块往前整理
        {
            vector<int> new_memory(m + 1, 0); // 新的内存
            int index = 1;                    // 新内存的索引
            for (int j = 1; j <= m; j++)      // 遍历旧内存
            {
                if (memory[j] != 0) // 如果内存块不为空
                {
                    new_memory[index] = memory[j]; // 将内存块复制到新内存
                    index++;                       // 增加新内存的索引
                }
            }
            // delete[] &memory;    // 释放旧内存
            memory = new_memory; // 更新旧内存为新内存
        }
    }
}