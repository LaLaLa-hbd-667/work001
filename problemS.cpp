//S - 查找(P2249)
#include <iostream>
#include <vector>
#include <algorithm> // lower_bound 需要这个头文件
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n); // 只开 n 大小，别开 n+1
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        
        // lower_bound 会在 v 中查找第一个 >= x 的位置
        auto it = lower_bound(v.begin(), v.end(), x);
        
        // 判断：如果没查到末尾，且查到的值确实等于 x
        if (it != v.end() && *it == x) {
            // 迭代器相减得到下标（从0开始），题目要求从1开始，所以 +1
            cout << (it - v.begin()) + 1 << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << "\n";
    return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;

vector <int> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }

    int x;
    for(int i=1;i<=m;++i){
        cin>>x;
        for(int j=0;j<v.size();++j){
            if(v[j]==x){
                cout<<j+1<<" ";
                break;
            }
            if(j=v.size()-1){
                cout<<"-1"<<" ";
                break;
            }
        }
    }


    return 0;
}
*/