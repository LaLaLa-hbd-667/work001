//Q - A-B 数对。(P1102)
#include <iostream>
#include <vector>
#include <unordered_map> // 引入哈希表

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    if (!(cin >> n >> c)) return 0;

    vector<long long> a(n);
    unordered_map<long long, int> mp; // 记录每个数字出现的次数

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++; // 统计频次
    }

    long long ans = 0;
    // 遍历每一个数，把它当作 B
    for (int i = 0; i < n; ++i) {
        long long target = a[i] + c; // 我们要找的目标是 A = B + C
        // 如果哈希表里有这个目标数，就把它出现的次数加到答案里
        if (mp.count(target)) {
            ans += mp[target];
        }
    }

    // 【特判 C == 0 的情况】
    // 如果 C = 0，那么 A = B。上面代码会把 A 和它自己配对。
    // 题目要求不同位置的数才算一对，所以每个数不能和自己配对，需要减去 N
    if (c == 0) {
        ans -= n;
    }

    cout << ans << "\n";

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <unordered_map> // 引入哈希表

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    if (!(cin >> n >> c)) return 0;

    vector<long long> a(n);
    unordered_map<long long, int> mp; // 记录每个数字出现的次数

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++; // 统计频次
    }

    long long ans = 0;
    // 遍历每一个数，把它当作 B
    for (int i = 0; i < n; ++i) {
        long long target = a[i] + c; // 我们要找的目标是 A = B + C
        // 如果哈希表里有这个目标数，就把它出现的次数加到答案里
        if (mp.count(target)) {
            ans += mp[target];
        }
    }

    // 【特判 C == 0 的情况】
    // 如果 C = 0，那么 A = B。上面代码会把 A 和它自己配对。
    // 题目要求不同位置的数才算一对，所以每个数不能和自己配对，需要减去 N
    if (c == 0) {
        ans -= n;
    }

    cout << ans << "\n";

    return 0;
}
*/