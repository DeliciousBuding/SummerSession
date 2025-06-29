#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;           // 找出其中最小的k个数
    priority_queue<int> pq;  // 最大堆
    unordered_set<int> seen; // 用于去重

    // 最大堆的大小限制在k个元素,如果堆的大小超过k个元素，则弹出堆顶元素
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (seen.count(x))
            continue;
        seen.insert(x);

        if(pq.size()<k)
        {
            pq.push(x);
        }
        else if(x<pq.top())
        {
            seen.erase(pq.top());
            pq.pop();
            pq.push(x);
        }
    }
    vector<int> result;
    while(!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }
    sort(result.begin(), result.end());
    for(int num:result)
    {
        cout << num << ' ';
    }
    return 0;
}
