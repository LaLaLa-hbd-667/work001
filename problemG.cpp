//G - 拼数。(P1012)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 自定义排序规则：如果 a+b > b+a，则 a 排在 b 前面
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n; // 千万别忘了输入 n！

    vector<string> v(n); 
    for (int i = 0; i < n; ++i) {
        cin >> v[i]; // 直接以字符串形式读取数字
    }

    // 使用自定义的比较函数进行排序
    sort(v.begin(), v.end(), cmp);

    // 拼接输出
    for (int i = 0; i < n; ++i) {
        cout << v[i];
    }
    cout << endl; // 养成好习惯，输出完换行

    return 0;
}