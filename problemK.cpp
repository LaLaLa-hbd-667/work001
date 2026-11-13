//K - 表达式括号匹配。(P1739)
/*
· #include <stack>：使用栈需要的头文件。
· stack<char> st;：声明一个存储字符类型的栈。
· st.push(ch);：将元素压入栈顶。
· st.pop();：弹出栈顶元素（注意它没有返回值）。
· st.empty();：判断栈是否为空。做栈的题目，empty() 判断几乎是必写的，防止越界崩溃。
*/
#include <iostream>
#include <stack> // 引入栈容器

using namespace std;

int main() {
    // 养成输入输出加速的好习惯
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> st; // 声明一个存放字符的栈
    char ch;

    // 逐个字符读取，直到读取到结束符 '@'
    while (cin >> ch && ch != '@') {
        if (ch == '(') {
            // 遇到左括号，压入栈中等待匹配
            st.push(ch);
        } else if (ch == ')') {
            // 遇到右括号，检查栈中是否有左括号可以配对
            if (st.empty()) {
                // 栈为空，说明这个右括号多余了，直接宣告失败
                cout << "NO\n";
                return 0; // 提前结束程序
            } else {
                // 栈不为空，弹出一个左括号与当前右括号抵消
                st.pop();
            }
        }
        // 其他字符（数字、字母、运算符等）直接忽略
    }

    // 遍历结束后，检查栈是否为空
    if (st.empty()) {
        cout << "YES\n"; // 全部完美匹配
    } else {
        cout << "NO\n";  // 栈里还有多余的左括号没被匹配
    }

    return 0;
}