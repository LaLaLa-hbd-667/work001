//T - 津津的储蓄计划。 (P5734)
/*
1. s.substr(a, b) 的边界问题：
   //s[a]开始保留，保留 b 个字符
   题目中说截取从第 a 个字符起 b 个字符。
   如果 a + b 超过了当前字符串的长度，substr 会自动截断到字符串末尾，
   不会报错崩溃，所以可以直接放心使用。
2. s.insert(a, str) 的参数顺序：
   注意，第一个参数是插入的位置（下标），第二个参数是要插入的字符串。
   千万不要写反了。
3. std::string::npos 是什么？
   find() 函数的返回值类型是 size_t（无符号整数）。
   当你没找到字符串时，它返回一个极大值 npos（通常是 4294967295，即无符号的 -1）。
   所以判断是否找到时，强烈建议写成 if (pos == string::npos)，
   而不是 if (pos == -1)（虽然编译器通常会自动转换，但前者更规范，不会引起警告）。
4. 关于性能：
   在 string 中间插入数据（操作 3）或截断数据（操作 2），
   底层会移动内存，时间复杂度是 O(N)。但由于这道题每次操作后都要输出整个字符串，
   输出的时间复杂度已经是 O(N) 了。因此，用 string 直接操作是完全可行的，
   不需要用到 list 或平衡树这些更复杂的结构。
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. 输入输出加速，应对大量字符串的读写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q)) return 0;

    string s;
    cin >> s;

    // 循环处理 q 次操作
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            string str;
            cin >> str;
            s += str; // 在末尾追加
            cout << s << "\n";
            
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            // substr(起始位置, 截取长度)
            // 截取后直接赋值给自己，覆盖原文档
            s = s.substr(a, b);     //s[a]开始保留
            cout << s << "\n";
            
        } else if (op == 3) {
            int a;
            string str;
            cin >> a >> str;
            // 在第 a 个字符前面插入
            s.insert(a, str);   //s[a]开始插入,原来s[a]及后面的字符往后移
            cout << s << "\n";
            
        } else if (op == 4) {
            string str;
            cin >> str;
            // find 返回首次出现的字符串的字符串首个元素下标是s[n]，找不到返回 string::npos
            // 为了安全，用 size_t (无符号整数) 接收
            size_t pos = s.find(str); 
            
            if (pos == string::npos) {
                cout << -1 << "\n"; // 找不到输出 -1
            } else {
                cout << pos << "\n"; // 找到了输出下标
            }
        }
    }

    return 0;
}