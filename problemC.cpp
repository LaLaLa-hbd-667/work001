//C - 明明的随机数。(P1059)
#include <iostream>
#include <vector>
#include <algorithm> // 包含 sort 和 unique

using namespace std;

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 1. 排序：从小到大排，让相同的数字挨在一起
    sort(nums.begin(), nums.end());

    // 2. 去重：unique 会把不重复的元素移到前面，
    //    返回去重后最后一个元素的下一个位置的迭代器
    //    迭代器就是“高级的指针”或理解成“智能光标”，指向容器中的元素
    //    像unique这样的算法函数，它不知道自己要操作的容器的类型，所以它返回的是一个迭代器，而不是一个整数下标
    //    unique函数 执行完之后，会返回一个迭代器，指向去重后最后一个元素的下一个位置，即下面3的位置（就是下标为4的位置）
    // 注意：unique 只是把重复的挪到了后面，并没有真正删除它们，vector 的长度也没变
    auto it = unique(nums.begin(), nums.end());
        //
        /*
        假设你的 vector 原本是这样的，有重复元素，长度为 8：
        [1, 1, 2, 2, 3, 3, 4, 4]
        当你执行 unique(nums.begin(), nums.end()) 时，它的底层逻辑是这样的：
        1. 它只会检查“相邻”的重复元素（所以去重前通常必须先 sort 排序）。
        2. 它拿一个“快指针”往前探路，拿一个“慢指针”记录不重复的元素。
        3. 它把不重复的元素往前挪，覆盖掉前面重复的位置。
        操作过程示意图：
        ·原本：[1, 1, 2, 2, 3, 3, 4, 4] （长度 8）
        · 经过 unique 挪动后：[1, 2, 3, 4, 3, 3, 4, 4] （长度还是 8！）
        · 前半部分：去重后的有效元素 1, 2, 3, 4。
        · 后半部分：是被覆盖后留下的“垃圾数据”（原来后面没用的元素）。       
        */

        /*
        为什么要这么设计？直接删不行吗？
        因为 C++ 的算法库讲究“算法与容器分离”。

        unique 只负责“搬运”和“判断重复”，它不知道你用的是 vector 还是数组还是 list，
        所以它不能直接调用 vector 的删除功能（因为不同容器删除元素的开销完全不一样）。
        所以，C++ 搞了个“三步走”的标准套路：
        1. 排序：sort(nums.begin(), nums.end()); （把重复的聚在一起）
        2. 去重：auto it = unique(nums.begin(), nums.end()); 
          （把不重复的挪到前面，返回新逻辑结尾的迭代器）
        3. 真正删除：nums.erase(it, nums.end()); 
          （告诉 vector，把 it 到 end() 这段废数据删掉，长度才真正变小）   
        */

    // 3. 删除：将后面多余的元素真正从 vector 中抹除
    nums.erase(it, nums.end());

    // 4. 输出
    // 第一行输出不相同的随机数的个数
    cout << nums.size() << "\n";
    
    // 第二行输出排好序的随机数
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << " "; // 控制空格
    }
    cout << "\n";

    return 0;
}

/*
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // 定义一个 set
    set<int> s;
    
    // 循环读入数据并插入 set 中，它会自动帮你去重并排序
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x); 
    }

    // 输出数量
    cout << s.size() << "\n";

    // 使用 C++11 的范围 for 循环遍历 set 输出
    // 这种写法很优雅，不需要管下标
    bool first = true;
    for (int x : s) {
        if (!first) cout << " ";
        cout << x;
        first = false;
    }
    cout << "\n";

    return 0;
}
*/