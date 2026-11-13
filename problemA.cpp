//A - 询问学号。(P3156)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. 输入输出加速（因为数据量n高达2*10^6，不加这句极大概率超时）
    // 关闭C标准流与C++标准流的同步
    ios::sync_with_stdio(false);  

    // 解除cin与cout的绑定，使得cin不再自动刷新cout，进一步提高输入输出效率
    cin.tie(nullptr);   /*
                        默认情况下，cin 是绑定在 cout 上的（cin.tie() 默认返回 &cout）。
                        这导致了一个现象：每次你执行输入操作（比如 cin >> n）之前，
                        系统都会自动强制刷新一次输出缓冲区（把 cout 里的东西全打印出来）。
                        */

    int n, m;
    // 如果没有输入直接结束
    if (!(cin >> n >> m)) return 0; /*
                                语法原理：cin >> 是有返回值的cin >> n 这个表达式，
                                        并不是什么都不返回。它在成功读取数据后，
                                        会返回 cin 这个流对象本身。
                                        在 C++ 中，cin 可以被隐式转换成 bool 类型：
                                        · 如果成功读到了数据，cin 转换成 true。
                                        · 如果读取失败（比如遇到了文件结束符 EOF，或者你输入了字母给 int 变量），
                                          cin 转换成 false。
                                    */

    // 2. 使用 STL 中的 vector 存储学号
    // 初始化一个大小为 n 的 vector（如果不提前指定大小，不断 push_back 也可能会略微影响效率）
    vector<int> students(n); 
    
    // 循环读入 n 个学号
    // 注意：学号最大可达 10^9，普通的 int（通常最大 2*10^9）是装得下的
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }

    // 3. 处理 m 次查询
    for (int i = 0; i < m; ++i) {
        int query_idx;
        cin >> query_idx;
        
        // 题目说的第 i 个同学（从 1 开始），在 vector 中是 query_idx - 1 的位置（从 0 开始）
        cout << students[query_idx - 1] << "\n"; // 注意：输出换行用 "\n" 比 endl 快
    }

    return 0;
}