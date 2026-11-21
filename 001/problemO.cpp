//O - 约瑟夫问题。(P1996)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i + 1); // 存入编号 1 到 n
    }

    int i = 0; // 报数的起点
    
    // 只要数组里还有人，就继续
    while (!v.empty()) {
        // 1. 直接算出这次要被淘汰的人的下标（这就是你说的“巧妙”）
        //知道m了，于是第i+m-1个人就是要删掉的人，超一圈的人数了怎么办?——取余！%一圈的人数就行
        i = (i + m - 1) % v.size();
        
        // 2. 输出他
        printf("%d ", v[i]);
        
        // 3. 把他删掉
        v.erase(v.begin() + i);
        
        // 4. 关键点：删掉之后，不需要 i-- 吗？
        // 因为刚刚删掉了位置 i 的人，后面的人顶上来了。
        // 此时 i 正好指向了下一个人，而下一次报数，就是从这个人开始算“1”。
        // 所以下一轮开头，i 已经是正确的起始位置了，不需要任何移动！
    }

    return 0;
}