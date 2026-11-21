//J - 栈。(P3614) 
/*
使用它需要包含头文件 #include <stack>。
常用操作：

· st.push(x)：把 x 压入栈顶。
· st.pop()：弹出栈顶元素（注意：它没有返回值）。
· st.top()：获取栈顶元素的值（不弹出）。
· st.size()：获取当前栈内元素个数。
· st.empty()：判断栈是否为空（为空返回 true，否则返回 false）。
*/
/*
1. 多组数据的“大坑”：
   很多初学者写这道题时，把 stack<int> st; 定义在了全局或者 main 函数的开头。
   结果第一组数据跑完，第二组数据开始时，栈里还残留着上一组的元素。
   解决办法：像上面代码一样，把栈定义在 solve() 函数内部，或者 while 循环内部，
   利用局部变量的生命周期，每次循环结束它就会自动销毁重建。
2. pop() 不返回元素：
   在 C++ STL 中，st.pop() 仅仅是删除栈顶元素，它不会返回被删除的值。
   如果你想知道栈顶是谁，必须先用 st.top() 看一眼，然后再 st.pop()。
3. 数据类型 long long：
   虽然题目没截全 x 的数据范围，但在算法题里，没写明范围的整数，
   一律开 long long 最保险，防止被超大测试点卡掉。
*/
#include <iostream>
#include <string>
#include <stack> // 引入栈

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // 在每一组数据内部声明一个新的栈，这样每组数据互不影响，自动清空
    stack<long long> st; 
    
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        
        if (op == "push") {
            long long x;
            cin >> x;
            st.push(x); // 压栈
            
        } else if (op == "pop") {
            if (st.empty()) {
                cout << "Empty\n"; // 题目要求：此时栈为空则不进行弹出操作，输出 Empty
            } else {
                st.pop(); // 出栈
            }
            
        } else if (op == "query") {
            if (st.empty()) {
                cout << "Anguei!\n"; // 题目要求：此时栈为空输出 Anguei!
            } else {
                cout << st.top() << "\n"; // 查询栈顶，但不弹出
            }
            
        } else if (op == "size") {
            cout << st.size() << "\n"; // 输出大小
        }
    }
}

int main() {
    // 输入输出加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (cin >> T) {
        while (T--) {
            solve(); // 循环处理每组数据
        }
    }
    
    return 0;
}