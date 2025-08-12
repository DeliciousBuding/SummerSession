#include <bits/stdc++.h>
using namespace std;

// 解析货币字符串，返回对应的Knut总数
long long parseToKnut(const string &money)
{
    // 找到两个点的位置
    size_t pos1 = money.find('.');
    size_t pos2 = money.find('.', pos1 + 1);

    // 提取三个部分
    long long galleon = stoll(money.substr(0, pos1));
    long long sickle = stoll(money.substr(pos1 + 1, pos2 - pos1 - 1));
    long long knut = stoll(money.substr(pos2 + 1));

    // 转换为Knut总数
    // 1 Galleon = 17 Sickle = 17 * 29 Knut = 493 Knut
    // 1 Sickle = 29 Knut
    return galleon * 17 * 29 + sickle * 29 + knut;
}

// 将Knut总数转换为Galleon.Sickle.Knut格式
string formatMoney(long long totalKnut)
{
    bool isNegative = false;

    // 处理负数
    if (totalKnut < 0)
    {
        isNegative = true;
        totalKnut = -totalKnut;
    }

    // 计算各个币种的数量
    long long galleon = totalKnut / (17 * 29);
    totalKnut %= (17 * 29);

    long long sickle = totalKnut / 29;
    long long knut = totalKnut % 29;

    // 格式化输出
    string result = to_string(galleon) + "." + to_string(sickle) + "." + to_string(knut);

    if (isNegative)
    {
        result = "-" + result;
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(0);

    string price, pay;
    cin >> price >> pay;

    // 将价格和支付金额都转换为Knut
    long long priceKnut = parseToKnut(price);
    long long payKnut = parseToKnut(pay);

    // 计算找零（支付金额 - 应付金额）
    long long changeKnut = payKnut - priceKnut;

    // 输出找零
    cout << formatMoney(changeKnut) << endl;

    return 0;
}
