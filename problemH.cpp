//H - 数字反转（升级版）。(P1553)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 处理整数部分：翻转并去除前导零
string reverseInt(string s) {
    // STL: 翻转字符串
    reverse(s.begin(), s.end());
    
    // STL: 找到第一个不是 '0' 的字符
    size_t pos = s.find_first_not_of('0');
    
    // 如果全是0，直接返回 "0"
    if (pos == string::npos) {
        return "0";
    }
    
    // STL: 截取从 pos 开始到末尾的子串
    return s.substr(pos);
}

// 处理小数部分：翻转并去除末尾零
string reverseDec(string s) {
    // STL: 翻转字符串
    reverse(s.begin(), s.end());
    
    // STL: 找到最后一个不是 '0' 的字符
    size_t pos = s.find_last_not_of('0');
    
    // 如果全是0（比如输入的是 0.00），只保留一个 "0"
    if (pos == string::npos) {
        return "0";
    }
    
    // STL: 截取从 0 开始，长度为 pos + 1 的子串
    return s.substr(0, pos + 1);
}

int main() {
    // 优化输入输出速度（可选）
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    // 1. 处理小数
    // 使用 find 查找 '.'，如果没找到会返回 string::npos
    /*
    1. string::npos 到底是个什么东西？
       string 的 find 函数如果找到了字符，会返回该字符所在的下标（索引，比如 0, 1, 2...）。
       那如果没找到呢？C++ 规定不能返回 -1，因为 find 函数的返回值类型是 size_t（无符号整数），
       -1 会被转换成一个极大的正数。
       为了统一，C++ 在 string 类里定义了一个静态常量 string::npos。
       它的值通常是 size_t 类型能表示的最大值（比如 18446744073709551615）。
       因为字符串根本不可能有这么长，所以用这个数字来代表“绝对找不到”。
    2. 它和 set::end() 的区别在哪？
       虽然作用一样，但性质有区别：
     · 类型不同：end() 返回的是迭代器（可以理解为指针），所以要解引用 *it；
       而 find() 返回的是下标（整数）。
     · 比较对象不同：对于 set，我们拿结果和 s.end() 比；对于 string，
       我们拿结果和 string::npos 比。
    */
    
    if (s.find('.') != string::npos) {
        size_t pos = s.find('.');
        // 截取整数部分和小数部分
        string intPart = s.substr(0, pos);
        string decPart = s.substr(pos + 1);
        
        // 分别处理并拼接
        cout << reverseInt(intPart) << "." << reverseDec(decPart) << "\n";
    } 
    // 2. 处理分数
    else if (s.find('/') != string::npos) {
        size_t pos = s.find('/');
        string num = s.substr(0, pos); // 分子
        string den = s.substr(pos + 1); // 分母
        
        // 分子分母分别用 reverseInt 处理（分子分母都不能有前导零）
        cout << reverseInt(num) << "/" << reverseInt(den) << "\n";
    } 
    // 3. 处理百分数
    else if (s.find('%') != string::npos) {
        size_t pos = s.find('%');
        string num = s.substr(0, pos);
        
        // 数字部分按整数处理，后面加上 '%'
        cout << reverseInt(num) << "%\n";
    } 
    // 4. 处理纯整数
    else {
        cout << reverseInt(s) << "\n";
    }

    return 0;
}