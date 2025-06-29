#include <bits/stdc++.h>
using namespace std;

// 可供申请的楼盘套数
int m;

// 申请人信息结构体
struct P
{
    char id[19];   // 身份证号
    int social;    // 社保缴纳月数
    int area;      // 自有住房面积
    char date[11]; // 申报时间

    // 重载小于运算符用于排序
    bool operator<(const P &b) const
    {
        // 刚需且社保不足条件的申请者排在最后(社保<=24个月且无房)
        if (area == 0 && social <= 24)
            return 0;
        if (b.area == 0 && b.social <= 24)
            return 1;
        // 如果 a 是刚需且社保不足，而 b 不是，则 a < b 为 false，a 排在 b 后面。
        // 如果 b 是刚需且社保不足，而 a 不是，则 a < b 为 true，a 排在 b 前面。

        //  住房面积小的优先(改善性需求)
        if (area != b.area)
            return area < b.area;

        // 对于刚需(无房)，社保月数多的优先
        if (area == 0 && social != b.social)
            return social > b.social;
        // 如果 a.social > b.social，则返回 true，这意味着 a < b 成立。也就是说，a 的社保月数比 b 多，但 a < b 却为真，这表示在排序时，a 应该排在 b 的前面。

        // 同等条件下按申报时间排序
        // 比较年份(格式MM-DD-YYYY)
        for (int i = 6; i < 10; ++i)
            if (date[i] != b.date[i])
                return date[i] < b.date[i];
        // 比较月份
        for (int i = 0; i < 2; ++i)
            if (date[i] != b.date[i])
                return date[i] < b.date[i];
        // 比较日期
        for (int i = 3; i < 5; ++i)
            if (date[i] != b.date[i])
                return date[i] < b.date[i];
        return 0;
    }
};

// 所有申请人数组指针
P *p;

// 从二进制文件读取申请人数据
P *getMess(int &n)
{
    FILE *fp;
    fp = fopen("house.bin", "rb");
    // 读取文件末尾的总申请人数
    fseek(fp, -1 * (long)sizeof(int), 2); // 2表示SEEK_END
    fread(&n, sizeof(int), 1, fp);
    // 回到文件开头
    rewind(fp);
    // 分配内存并读取所有申请人数据
    P *tmp = new P[n];
    fread(tmp, sizeof(P), n, fp);
    fclose(fp);
    return tmp;
}

// 总申请人数
int n;

// 身份证号到数组索引的映射
map<string, int> mp;

// 处理单次查询
void work()
{
    // 读取查询的身份证号
    char c[19];
    scanf("%s", c);
    string s = c;

    // 查找对应的数组索引
    int id = mp[s];

    // 计算排序后该申请人的排名范围
    int l = lower_bound(p, p + n, p[id]) - p + 1; // 起始排名 0开始的索引,+1转换为在相同分数的人之间的排名
    int r = upper_bound(p, p + n, p[id]) - p;     // 结束排名 这是在相同分数的人之间的排名
    // 得到[l,r)区间的排名
    //  lower_bound和upper_bound函数的作用是查找一个有序区间中

    // lower/upper_bound(first迭代器,last迭代器,value要查找的值)
    // lower_bound 返回第一个大于等于 value 的元素的迭代器
    // upper_bound 返回第一个大于 value 的元素的迭代器

    // 输出查询结果
    if ((p[id].area == 0 && p[id].social <= 24) || l > m)
        // 不符合条件或排名超出可供房源数量
        cout << "Sorry" << endl;
    else if (l == r)
        // 该排名只有一人
        cout << l << endl;
    else
        // 该排名有多人
        // 如果同排名人数超过剩余房源，输出"剩余可分配数/总同排名人数"格式
        // 否则输出排名区间
        if (r > m)
        {
            cout << (m - l + 1) << "/" << (r - l + 1) << endl; // 输出"A/B"格式，表示B人中选A人
        }
        else
        {
            cout << l << " " << r << endl; // 输出排名区间
        }
}

int main()
{
    // 读取申请人数据
    p = getMess(n);

    // 按规则排序
    sort(p, p + n);

    // 建立身份证号到索引的映射
    for (int i = 0; i < n; ++i)
    {
        string s = p[i].id;
        mp[s] = i;
    }

    // 读取查询参数
    int T; // 查询次数
    cin >> m >> T;

    // 处理每个查询
    while (T--)
        work();

    return 0;
}