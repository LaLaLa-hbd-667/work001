//B - 排序。(P1177)
#include <iostream>
#include <vector>
#include <algorithm> // 必须包含这个头文件，才能使用 sort

using namespace std;

int main() {
    // 1. 输入输出加速，好习惯
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // 读取数字个数 N
    if (!(cin >> n)) return 0;

    // 2. 使用 vector 存储数据
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 3. 核心：使用 STL 的 sort 函数进行排序
    // nums.begin() 是数组起始位置，nums.end() 是结束位置
    // sort 默认会将它们按从小到大的顺序排好
    sort(nums.begin(), nums.end());

    // 4. 输出结果
    for (int i = 0; i < n; ++i) {
        cout << nums[i];
        // 格式控制：数字之间用空格隔开，最后一个数字后面不带空格（更严谨）
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << "\n"; // 最后输出一个换行符

    return 0;
}
/*
记得加上 #include <functional> (通常包含在 iostream 里了)
sort(nums.begin(), nums.end(), greater<int>()); 
*/