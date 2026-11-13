//N - 机器翻译(P1540)
/*
学习笔记与避坑指南：

1. STL queue 的常用操作：
   · q.push(x)：入队（放到队尾）。
   · q.pop()：出队（弹出队头元素，无返回值）。
   · q.front()：获取队头元素。
   · q.size()：获取当前队列大小。
   · q.empty()：判断是否为空。

2. FIFO（先进先出）思想：队列是极其基础的数据结构。
以后遇到缓存淘汰机制（比如 LRU 算法的简化版）、广度优先搜索（BFS），都会大量用到它。

3. queue 没有 find 方法：
很多新手刚学 STL 时，会想直接在 queue 里找有没有某个元素，这是做不到的（会报错）。
必须像上面的代码一样，引入辅助结构（布尔数组、set、map）来记录状态。

*/
//

//C++ 代码实现（queue + 布尔数组）
//这是算法竞赛中最推荐的写法，速度极快（O(1) 查询）。

//需解决问题：
//1.需要找到一个容器，根据变量的存入顺序存储（这个顺序涉及后面的元素删除删哪个）
//2.因为队列不能find，所以用memory变量来记录新变量是否已经存入过了
#include <iostream>
#include <queue> // 引入队列

using namespace std;

// 题目说明单词大小不超过 1000，所以开 1005 足够了
bool in_memory[1005]; 

int main() {
    // 输入输出加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    queue<int> q; // 维护内存中的单词顺序
    int ans = 0;  // 查字典的次数

    for (int i = 0; i < N; ++i) {
        int word;
        cin >> word;

        // 如果这个单词不在内存中
        if (!in_memory[word]) {
            ans++; // 需要去外存查字典

            // 如果内存已满，踢出最早进入的单词
            if (q.size() == M) {
                int old_word = q.front(); // 获取队头元素
                q.pop();                  // 弹出队头
                in_memory[old_word] = false; // 标记为不在内存中
            }

            // 将新单词存入内存
            q.push(word);
            in_memory[word] = true;
        }
        // 如果 in_memory[word] 为 true，说明已经在内存里了，直接忽略
    }

    cout << ans << "\n";

    return 0;
}
/*
进阶：纯 STL 写法（如果你想多用 STL 容器）
如果题目没有限制单词大小（比如单词是字符串，或者数字达到了 10^9），
我们就不能开这么大的数组了。这时候可以用 std::unordered_set 来代替布尔数组。
它底层是哈希表，查找和插入的平均时间复杂度也是 O(1)。
*//*
#include <iostream>
#include <queue>
#include <unordered_set> // 引入哈希集合

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    queue<int> q;
    unordered_set<int> mem_set; // 记录内存中存在的单词
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        int word;
        cin >> word;

        // 在哈希集合中查找，找不到说明不在内存
        if (mem_set.find(word) == mem_set.end()) {
            ans++;
            
            if (q.size() == M) {
                int old_word = q.front();
                q.pop();
                mem_set.erase(old_word); // 从集合中移除
            }
            
            q.push(word);
            mem_set.insert(word); // 加入集合
        }
    }

    cout << ans << "\n";

    return 0;
}
*/
