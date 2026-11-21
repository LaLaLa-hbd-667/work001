//E - 小鱼比可爱。(P1428)
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 遍历每条鱼
    for (int i = 0; i < n; ++i) {
        int count = 0;
        // 遍历该鱼左边的所有鱼
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                count++;
            }
        }
        cout << count << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}