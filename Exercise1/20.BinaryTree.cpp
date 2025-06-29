#include <bits/stdc++.h>
using namespace std;

/*
    已知二叉树的前序遍历和中序遍历，递归求出后序遍历
    前序遍历：根左右
    中序遍历：左根右
    后序遍历：左右根
*/
string getPostOrder(string &preOrder, string &inOrder)
{
    // 如果为空，返回空字符串
    if (preOrder.empty() || inOrder.empty())
        return "";

    // 前序遍历的第一个字符是根节点
    char root = preOrder[0];

    // 在中序遍历中找到根节点的位置
    int pos = inOrder.find(root);

    // 左子树的前序和中序
    string leftPre = preOrder.substr(1, pos);//刚好长度是一样的
    string leftIn = inOrder.substr(0, pos);
    //substr(开始位置，截取长度) find(char)

    // 右子树的前序和中序
    string rightPre = preOrder.substr(pos + 1);
    string rightIn = inOrder.substr(pos + 1);

    // 递归拼接左子树、右子树的后序遍历，再加上根节点
    return getPostOrder(leftPre, leftIn) + getPostOrder(rightPre, rightIn) + root;
}

int main()
{
    while (1)
    {
        int t;
        cin >> t;
        
        if (t == 0)
            return 0;
        string preOrder, inOrder;
        cin >> preOrder >> inOrder;

        // 已知前序中序遍历求后序遍历
        cout << getPostOrder(preOrder, inOrder) << endl;
    }
}