//L - 后缀表达式。(P1449)
/*
学习笔记与重点提示：

1. 多位数拼接算法（非常常用！）：

   num = num * 10 + (ch - '0');
 
   这是处理字符串中多位数最经典的模板。
   比如读入 '2' 和 '5'，第一次 num = 0*10 + 2 = 2，第二次 num = 2*10 + 5 = 25。
   遇到 . 或者空格时再压栈并清零。

2. pop() 的顺序（极其容易写反）：

   假设栈里依次压入了 5 和 2（先5后2）。遇到 - 号时：
   · 第一次 st.top() 拿到的是 2，这是减数（b）。
   · 第二次 st.top() 拿到的是 5，这是被减数（a）。
   · 计算的是 a - b （即 5 - 2 = 3）。如果写成了 b - a，结果就是 -3 了，除法同理。

3. 数据类型：
   虽然题目没给具体数据范围，但在算法题里，连乘、连加很容易超出 int 的范围（变成负数），
   所以直接用 long long 是最保险的做法。

4. std::stack 的常用操作回顾：
   · st.push(x)：压栈
   · st.top()：看栈顶元素
   · st.pop()：弹栈（无返回值）
   · st.empty()：判空（本题因为最后总是有 @ 结束且表达式合法，
   最终栈里肯定只有一个结果，所以可以不判空，但实际开发中弹栈前一定判空）。
   
*/
#include <iostream>
#include <string>
#include <stack> // 引入栈容器

using namespace std;

int main() {
    // 输入输出加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s; // 读入整个字符串

    stack<long long> st; // 声明一个存数字的栈，用 long long 防止乘法溢出
    long long num = 0;   // 用来拼接多位数

    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];

        // 1. 如果是数字，拼接起来
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        } 
        // 2. 如果遇到 '.'，说明一个完整的数字结束了
        else if (ch == '.') {
            st.push(num); // 把数字压入栈中
            num = 0;      // 清零，准备拼接下一个数字
        } 
        // 3. 如果是运算符
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // 注意：先弹出的是右操作数，后弹出的是左操作数
            long long b = st.top(); 
            st.pop();
            long long a = st.top();
            st.pop();

            // 根据运算符计算结果
            long long result = 0;
            if (ch == '+') result = a + b;
            else if (ch == '-') result = a - b;
            else if (ch == '*') result = a * b;
            else if (ch == '/') result = a / b; // 题目保证除数不为0，且向0取整符合C++规则

            // 将计算结果重新压入栈中，参与后续运算
            st.push(result);
        } 
        // 4. 遇到 '@'，结束
        else if (ch == '@') {
            break;
        }
    }

    // 最终栈顶剩下的唯一元素就是最终结果
    cout << st.top() << "\n";

    return 0;
}