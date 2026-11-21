//M - 测测你的矩阵乘法。(P3615) 
/*
核心优化技巧：循环顺序（IKJ优化）
最基础的矩阵乘法写法（IJK）是这样的：

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        c[i][j] = 0;
        for (int k = 0; k < n; k++) {
            c[i][j] += a[i][k] * b[k][j];
        }
    }
}

致命缺陷：在最内层的 k 循环中，b[k][j] 的 k 在不断增加，但 j 不变。因为 C++ 二维数组是按行存储的，这就导致每次读取 b[k][j] 都会跨越一整行去读取内存，CPU 缓存（Cache）命中率极低，速度非常慢。

优化方法（调整为 IKJ 顺序）：
将 k 循环放到中间，j 循环放到最内层。这样 c[i][j] 和 b[k][j] 都是连续读取内存的，CPU 缓存极其友好，速度能提升数倍！

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = 0; // 初始化
    for (int k = 0; k < n; k++) {
        int temp = a[i][k]; // 把 a[i][k] 提出来，避免重复读取内存
        for (int j = 0; j < n; j++) {
            c[i][j] += temp * b[k][j];
        }
    }

*/
#include <bits/stdc++.h>
const int n = 512, N = n;

void multiply (int c[N][N], int a[N][N], int b[N][N]) {
    // 核心优化：改变循环顺序为 i -> k -> j
    for (int i = 0; i < n; ++i) {
        // 先把 C 矩阵的第 i 行清零
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
        }
        
        for (int k = 0; k < n; ++k) {
            // 提前取出 a[i][k]，避免在内层循环中反复寻址
            int temp = a[i][k];
            
            // 如果 temp 是 0，可以直接跳过，省去无用的乘法计算（针对特定数据的剪枝）
            if (temp == 0) continue; 
            
            // 最内层连续访问 c[i] 和 b[k] 的内存
            for (int j = 0; j < n; ++j) {
                c[i][j] += temp * b[k][j];
            }
        }
    }
}

int c[N][N], a[N][N], b[N][N];
int main() {
    int seedA, seedB;
    // 注意：这里用 scanf 比 cin 快，因为题目数据量大
    if(scanf("%d%d", &seedA, &seedB) != 2) return 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = ((i | j) + j) ^ seedA;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = ((i & j) + i) ^ seedB;
        }
    }
    
    multiply(c, a, b);
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum ^= c[i][j]; // 求异或和
        }
        printf("%d\n", sum);
    }
    return 0;
}