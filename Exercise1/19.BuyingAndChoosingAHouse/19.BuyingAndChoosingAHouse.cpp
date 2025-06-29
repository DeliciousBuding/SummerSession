#include <bits/stdc++.h>
using namespace std;

struct people
{
    char id[19];   /* 身份证号码 */
    int social;    /* 社保缴纳月数 */
    int area;      /* 现有住房面积 */
    char date[11]; /* 申报日期 */
};

// 刚需排序函数：社保月数多优先，时间早优先
bool cmpRigid(const people &a, const people &b)
{
    if (a.social != b.social)
        return a.social > b.social;
    return strcmp(a.date, b.date) < 0;
}

// 改善排序函数：面积小优先，时间早优先
bool cmpImprove(const people &a, const people &b)
{
    if (a.area != b.area)
        return a.area < b.area;
    return strcmp(a.date, b.date) < 0;
}

string getAns(string A, people *person, int n, int m)
{
    // 将申请者分为刚需和改善两类
    vector<people> rigid, improve;
    for (int i = 0; i < n; i++)
    {
        if (person[i].area == 0 && person[i].social > 24) // 刚需：无房且社保>24个月(2年)
            rigid.push_back(person[i]);
        else if (person[i].area > 0) // 改善：有房
            improve.push_back(person[i]);
    }

    // 分别排序
    sort(rigid.begin(), rigid.end(), cmpRigid);
    sort(improve.begin(), improve.end(), cmpImprove);

    // 合并为最终排序结果
    vector<people> finalRank;
    finalRank.insert(finalRank.end(), rigid.begin(), rigid.end());
    finalRank.insert(finalRank.end(), improve.begin(), improve.end());

    // 寻找查询ID在排名中的位置
    int pos = -1;
    for (size_t i = 0; i < finalRank.size(); i++)
    {
        if (strcmp(finalRank[i].id, A.c_str()) == 0)
        {
            pos = i;
            break;
        }
    }

    // 如果未找到或排名超出房源数，返回Sorry
    if (pos == -1 || pos >= m)
        return "Sorry";

    // 确定该申请人是哪种需求类型
    bool isRigid = false;
    for (size_t i = 0; i < rigid.size(); i++)
    {
        if (strcmp(rigid[i].id, A.c_str()) == 0)
        {
            isRigid = true;
            break;
        }
    }

    // 寻找所有和该申请者条件相同的人
    vector<int> sameRank;
    for (size_t i = 0; i < finalRank.size(); i++)
    {
        // 判断是否条件相同
        bool isSame = false;
        // 刚需比较：社保月数和申报时间
        if (isRigid && finalRank[i].area == 0 && finalRank[i].social > 24)
        {
            if (finalRank[i].social == finalRank[pos].social &&
                strcmp(finalRank[i].date, finalRank[pos].date) == 0)
                isSame = true;
        }
        // 改善比较：住房面积和申报时间
        else if (!isRigid && finalRank[i].area > 0)
        {
            if (finalRank[i].area == finalRank[pos].area &&
                strcmp(finalRank[i].date, finalRank[pos].date) == 0)
                isSame = true;
        }

        if (isSame)
            sameRank.push_back(i);
    }

    // 只有一个人，直接返回排名+1
    if (sameRank.size() == 1)
        return to_string(pos + 1);

    // 找出相同条件的排名范围
    int minRank = *min_element(sameRank.begin(), sameRank.end());
    int maxRank = *max_element(sameRank.begin(), sameRank.end());

    // 判断是否超出剩余房源数
    if (maxRank >= m)
    {
        // 计算能中签的人数和总人数
        int remain = m - minRank; // 剩余可分配的房源数
        if (remain <= 0)
            return "Sorry"; // 没有剩余房源

        int total = sameRank.size();
        return to_string(remain) + "/" + to_string(total);
    }
    else
    {
        // 返回排名区间
        return to_string(minRank + 1) + " " + to_string(maxRank + 1);
    }
}

// 添加 getMess 函数实现
people *getMess(int &n)
{
    // 打开二进制文件
    FILE *fp = fopen("house.bin", "rb");
    if (fp == NULL)
    {
        cerr << "Cannot open file" << endl;
        exit(-1);
    }

    // 读取报名人数 n
    fseek(fp, -1 * (long)sizeof(int), SEEK_END); // 移动到文件尾部的整数位置
    fread(&n, sizeof(int), 1, fp);

    // 回到文件开头
    rewind(fp);

    // 分配内存并读取所有报名者信息
    people *tmp = new people[n];
    fread(tmp, sizeof(people), n, fp);

    // 关闭文件
    fclose(fp);

    return tmp;
}

int main()
{
    people *person; /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */
    int n;          /* n为报名人数，通过调用函数getMess获取 */
    person = getMess(n);

    int m, T;
    cin >> m >> T; // m为每人可购买的房屋数量，T为测试用例数
    cin.ignore();
    for (int i = 0; i < T; i++)
    {
        string A;
        getline(cin, A); // 身份证号码
        cout << getAns(A, person, n, m) << endl;
    }

    delete[] person; // 释放动态分配的内存
    return 0;
}